#ifndef KIPC_H
#define KIPC_H 

#include <ipc/ipc.h>

typedef struct MsgNode {
    IPC_MSG msg;
    struct MsgNode* next;
}MsgNode;


 
  
int sys_send(IPC_MSG* msg) ;


int sys_recv(IPC_MSG* msg) ;

#endif 