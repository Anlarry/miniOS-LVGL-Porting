#include <ipc/ipc.h>
#include <gui/gui.h>
void main(int arg, char *argv[]) {
    IPC_MSG msg = {
       .src = -1,
       .dst = 4,
       .type = P2P,
       .data = {Button,50, 50}
    };
    send(&msg);
    while(1) {

    }
}