#include <ipc/ipc.h>
#include "kipc.h"

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

void sys_signal_send(PROCESS* proc)
{
    STACK_FRAME regs;
    memcpy(&regs, &proc->task.regs, sizeof(STACK_FRAME));

    // change this proc(B)'s eip to warper function
    // warp function includes { handler, signal_return }
    // then first execuate handler function
    // then second call signal_return to kernel

}

void sys_signal_return()
{

}


int boardcast(IPC_MSG* msg)
{
    PROCESS *proc;
    for(int i=0; i<NR_PCBS; i++)
    {
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

int p2p(IPC_MSG* msg)
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

int sys_send(IPC_MSG* msg) {

    msg->src = p_proc_current - proc_table;
    int dst_id = msg->dst;

    switch(msg->type)
    {
        case Signal :
        {
            //PROCESS* proc = proc_table+dst_id;
            //sys_signal_send(proc, );
            break;
        }
        case P2P :
        {
            return p2p(msg);
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