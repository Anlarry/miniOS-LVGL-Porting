#include <ipc/ipc.h>

typedef struct MsgNode {
    IPC_MSG msg;
    IPC_MSG* next;
}MsgNode;

static MsgNode MsgBuf[100];

static MsgNode* MsgList[12];


int msg_malloc() {

}

int msg_free() {

}

int sys_send(IPC_MSG* msg) {

}

int sys_recv(IPC_MSG* msg) {

}