#include <ipc/ipc.h>

typedef struct MsgNode {
    IPC_MSG msg;
    IPC_MSG* next;
}MsgNode;

static MsgNode MsgBuf[100];

static MsgNode* MsgList[12];

#define NULL 0


struct MsgNode* msg_malloc() {

}

void msg_free(struct MsgNode* msgNode) {

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