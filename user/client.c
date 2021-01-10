#include <ipc/ipc.h>

void main(int arg, char *argv[]) {
    IPC_MSG msg = {
       .src = -1,
       .dst = 4,
       .type = Button,
       .data = {50, 50}
    };
    send(&msg);
    while(1) {

    }
}