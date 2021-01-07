#ifndef KIPC_H
#define KIPC_H 

#include <ipc/ipc.h>

int sys_send(IPC_MSG* msg) ;


int sys_recv(IPC_MSG* msg) ;

#endif 