#include <ipc/ipc.h>
#include <stddef.h>
#include <gui/gui.h>
#include <gui/api.h>
#include <ipc/signal.h>

void Test() {
    for(int i = 0; i < 5; i++) ;
    return ;
}

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

    lv_obj_set_x_c(btn, 400);
    lv_obj_set_y_c(btn, 400);

    memset(&msg, 0, sizeof(msg));
    msg.dst = 4;
    msg.type = P2P_A;
    msg.data[0] = RegisterCallback;
    msg.data[1] = Handler;
    msg.data[2] = Test;
    send(&msg);

    while(1) {
        
    }
}