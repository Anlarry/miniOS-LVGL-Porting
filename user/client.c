#include <ipc/ipc.h>
#include <stddef.h>
#include <gui/gui.h>

void main(int arg, char *argv[]) {
    IPC_MSG msg = {
        .src = -1,
        .dst = 4,
        .type = P2P,
        .data = {0}
    };
    GUI *gui_data = (GUI*)msg.data;
    gui_data->type = Button;
    gui_data->data[0] = 50;
    gui_data->data[1] = 50;
    send(&msg);
    while(1) {
        
    }
}