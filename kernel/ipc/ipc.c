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

static MsgNode* MsgList[12];

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

void sys_signal_send(PROCESS* proc...)
{

}

void sys_signal_return()
{

}

int sys_send(IPC_MSG* msg) {
    
    struct MsgNode* Node = msg_malloc();

    if(Node == NULL) return FULL;
    msg->src = p_proc_current - proc_table;


    //int src_id = msg->msg.src;
    int dst_id = msg->dst;
    struct MsgNode* NodePtr  = MsgList[dst_id];
    switch(msg->type)
    {
        Signal_Send :
        {
            PROCESS* proc = proc_table+dst_id;
            sys_signal_send(proc, );
            break;
        }
        Signal_Return :
        {
            sys_signal_return();
            break;
        };
        default :
        {
            while(NodePtr != NULL && NodePtr->next != NULL)
            {
                NodePtr = NodePtr->next;
            }
            if(NodePtr == NULL)
            {
                MsgList[dst_id] = Node;
            }
            else
            {
                NodePtr->next = Node;
                Node->next = NULL;
            }
            memcpy(&(Node->msg), msg, sizeof(IPC_MSG));
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