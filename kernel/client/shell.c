#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"

#include <ipc/ipc.h>

void Shell() {
    // while(1){}
    IPC_MSG msg ;
    int res = recv(&msg);
    while(res == EMPTY) {
        res = recv(&msg);
    }
    exec("orange/client.bin");
}