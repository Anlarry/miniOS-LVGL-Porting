#include <ipc/ipc.h>
#include <stddef.h>
#include <gui/gui.h>
#include <gui/api.h>

void main(int arg, char *argv[]) {
    IPC_MSG msg = {
        .src = -1,
        .dst = 4,
        .type = P2P_S,
        .data = {0}
    };
    GUI *gui_data = (GUI*)msg.data;
    gui_data->type = Button;
    gui_data->data[0] = 50;
    gui_data->data[1] = 50;
    send(&msg);

    recv(&msg);
    int btn = msg.data[0];
    lv_obj_set_x_c(btn, 100);
    lv_obj_set_x_c(btn, 100);

    while(1) {
        
    }
}