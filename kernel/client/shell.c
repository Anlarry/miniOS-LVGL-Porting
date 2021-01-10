#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"

#include <ipc/ipc.h>

void Shell() {
    IPC_MSG msg ;
    int res = recv(&msg);
    while(res == EMPTY || msg.type != Untar) {
        res = recv(&msg);
    }
    for(int i=0; i<50000000; i++);
    exec("orange/client.bin");
}