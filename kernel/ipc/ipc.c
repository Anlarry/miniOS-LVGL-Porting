#include <ipc/ipc.h>
#include "kipc.h"
#include <ipc/signal.h>

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"

static MsgNode MsgBuf[MSG_BUF_SIZE];
static int isFree[MSG_BUF_SIZE];

static MsgNode* MsgList[12] __attribute__((section(".data"))); 

#define NULL 0

MsgNode* msg_malloc() {
    for(int i = 0; i < MSG_BUF_SIZE; i++) {
        if(isFree[i] == NULL) {
            isFree[i] = 1;
            memset(&MsgBuf[i], 0, sizeof(MsgNode));
            return &MsgBuf[i];
        }
    }
    return NULL ; 
}

int msg_free(MsgNode* msgNode) {
    int idx = msgNode - MsgBuf;
    if(idx < 0 || idx >= MSG_BUF_SIZE) 
        return -1;
    isFree[idx] = 0;
    return 0;
}






void sys_signal_send(PROCESS* proc, IPC_MSG *msg_p)
{
    STACK_FRAME regs;
    memcpy(&regs, &proc->task.regs, sizeof(STACK_FRAME));
    IPC_MSG msg ;
    memcpy(&msg, msg_p, sizeof(IPC_MSG));

    // change this proc(B)'s eip to warper function
    // warp function includes { handler, signal_return }
    // then first execuate handler function
    // then second call signal_return to kernel
    // TODO
    disable_int();

    int B_cr3 = proc->task.cr3;
    int A_cr3;
    /* change cr3 to B_cr3 */
    __asm__  (
        "mov %%cr3, %%eax\n"
        "mov %%ebx, %%cr3\n"
        : "=a"(A_cr3)
        : "b"(B_cr3)
        :
    );
    
    uint16_t B_ss = regs.ss;
    uint16_t A_es ;
    
    /* change es to B_ss */
    __asm__  (
        "mov %%es, %%ax\n"
        "mov %%ebx, %%es\n"
        : "=a"(A_es)
        : "b"(B_ss)
        :
    );
    
    /* save context */ 
    int context_size = 8 + 4 + 6; // 18
    int start = regs.esp - context_size;
    for(uint8_t* p = start, *sf = proc->task.esp_save_syscall; p < regs.esp; p++, sf++) {
        __asm__ ( 
            "mov %%ax, %%es:(%%edi)"
            : 
            : "a"(*sf), "D"(p)
            :
        );
    }

    /* push para */
    start -= sizeof(Sigaction);
    Sigaction sigaction = {
        .handler = msg.data[2]
    };
    for(uint8_t* p = start, *sf = &sigaction, i = 0; i < sizeof(Sigaction);i++, p++, sf++) {
        __asm__ (
            "mov %%ax, %%es:(%%edi)"
            :
            : "a"(*sf), "D"(p)
            :
        );
    }

    /* Handler return address */
    start -= sizeof(uint32_t);


    /* switch to Handler */
    // proc->task.regs.esp = start;
    // proc->task.regs.eip = msg.data[1];
    uint32_t *context_p = proc->task.esp_save_syscall;
    *(context_p + 13) =  msg.data[1];
    *(context_p + 16) = start;

    /*  reverse  */
    __asm__ __volatile__ (
        "mov %0, %%es\n"
        : 
        : "r"(A_es)
        :
    );
    __asm__ __volatile__ (
        "mov %0, %%cr3\n"
        :
        : "r"(A_cr3)
        :
    );

    enable_int();
}

void sys_signal_return(IPC_MSG* msg)
{
    STACK_FRAME regs;

    // copy saved regs from stack to  this regs
    // to some operation to compute true address
    int ebp = msg.data[1];
    int esp_syscall = p_proc_current->task.esp_save_syscall;
    int last_esp = ebp+ sizeof(Sigaction);    //int save esp
    memcpy(&regs, last_esp, sizeof(STACK_FRAME));
    memcpy(&esp_syscall, &regs, sizeof(STACK_FRAME));
    //
}


int boardcast(IPC_MSG* msg)
{
    PROCESS *proc;
    for(int i=0; i<NR_PCBS; i++)
    {
        if(i == p_proc_current - proc_table)
        {
            continue;
        }

        struct MsgNode* Node = msg_malloc();
        if(Node == NULL) return FULL;

        proc = proc_table+i;
        struct MsgNode* NodePtr  = MsgList[i];
        if(proc->task.stat == READY || proc->task.stat == SLEEPING )
        {
            while(NodePtr != NULL && NodePtr->next != NULL)
            {
                NodePtr = NodePtr->next;
            }
            if(NodePtr == NULL)
            {
                MsgList[i] = Node;
            }
            else
            {
                NodePtr->next = Node;
                Node->next = NULL;
            }
            memcpy(&(Node->msg), msg, sizeof(IPC_MSG));
        }
    }

    return SUCCESS;
}

int p2p_a(IPC_MSG* msg)
{

    struct MsgNode* Node = msg_malloc();
    if(Node == NULL) return FULL;

    msg->src = p_proc_current - proc_table;
    int id = msg->dst;

    struct MsgNode* NodePtr  = MsgList[id];
    while(NodePtr != NULL && NodePtr->next != NULL)
    {
        NodePtr = NodePtr->next;
    }
    if(NodePtr == NULL)
    {
        MsgList[id] = Node;
    }
    else
    {
        NodePtr->next = Node;
        Node->next = NULL;
    }
    memcpy(&(Node->msg), msg, sizeof(IPC_MSG));
    return SUCCESS;
}

int p2p_s(IPC_MSG* msg) {
    struct MsgNode* Node = msg_malloc();
    if(Node == NULL) return FULL;

    msg->src = p_proc_current - proc_table;
    int id = msg->dst;

    struct MsgNode* NodePtr  = MsgList[id];
    while(NodePtr != NULL && NodePtr->next != NULL)
    {
        NodePtr = NodePtr->next;
    }
    if(NodePtr == NULL)
    {
        MsgList[id] = Node;
    }
    else
    {
        NodePtr->next = Node;
        Node->next = NULL;
    }
    memcpy(&(Node->msg), msg, sizeof(IPC_MSG));
    p_proc_current->task.stat = SLEEPING;
    return SUCCESS;
}

int ack(IPC_MSG* msg) {
    struct MsgNode* Node = msg_malloc();
    if(Node == NULL) return FULL;

    msg->src = p_proc_current - proc_table;
    int id = msg->dst;

    Node->next = MsgList[id];
    MsgList[id] = Node;

    memcpy(&(Node->msg), msg, sizeof(IPC_MSG));
    proc_table[msg->dst].task.stat = READY;
    return SUCCESS;
}



int sys_send(IPC_MSG* msg) {
    msg->src = p_proc_current - proc_table;
    int dst_id = msg->dst;

    PROCESS* proc;
    switch(msg->type)
    {
        case Signal :
        {
            switch(msg->data[0]) 
            {
                case SIG_SEND:
                    proc = proc_table+dst_id;
                    sys_signal_send(proc, msg);
                    break;
                case SIG_RETURN :
                    break;
            }
            break;
        }
        case P2P_A :
        {
            return p2p_a(msg);
            break;
        }
        case P2P_S :
        {
            return p2p_s(msg);
            break;
        }
        case ACK :
        {
            return ack(msg);
            break;
        }
        case Boardcast :
        {
            return boardcast(msg);
            break;
        };
        default :
        {
            break;
        }
    }

    return SUCCESS;
}

int sys_recv(IPC_MSG* msg) {
    int dst_id = p_proc_current - proc_table;
    // int dst_id = msg->dst;
    struct MsgNode* NodePtr = MsgList[dst_id];

    if(NodePtr == NULL)
    {
        return EMPTY;
    }
    MsgList[dst_id] = NodePtr->next;

    memcpy(msg, &(NodePtr->msg), sizeof(IPC_MSG));

    msg_free(NodePtr);
    return SUCCESS;
}