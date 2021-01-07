#include <ipc/ipc.h>
#include "kipc.h"

static MsgNode MsgBuf[MSG_BUF_SIZE];
static int isFree[MSG_BUF_SIZE];

static MsgNode* MsgList[12];

#define NULL 0

MsgNode* msg_malloc() {
    for(int i = 0; i < 100; i++) {
        if(isFree[i] == NULL) {
            return i;
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

int sys_send(IPC_MSG* msg) {

    struct MsgNode* send_msg = msg_malloc();

    if(send_msg == NULL) return FULL;
    memcpy(&(send_msg->msg), msg, sizeof(IPC_MSG));

    //int src_id = msg->msg.src;
    int dst_id = msg->dst;
    struct MsgNode* NodePtr  = MsgList[dst_id];

    while(NodePtr != NULL && NodePtr->next != NULL)
    {
        NodePtr = NodePtr->next;
    }
    if(NodePtr == NULL)
    {
        MsgList[dst_id] = send_msg;
    }
    else
    {
        NodePtr->next = send_msg;
        send_msg->next = NULL;
    }

    return SUCCESS;
}

int sys_recv(IPC_MSG* msg) {
    int dst_id = msg->dst;
    struct MsgNode* NodePtr = MsgList[dst_id];

    if(NodePtr == NULL)
    {
        return EMPTY;
    }
    MsgList[dst_id] = NodePtr->next;

    memcpy(msg, &(NodePtr->msg), sizeof(IPC_MSG));

    return SUCCESS;
}