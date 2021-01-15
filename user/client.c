#include <stdio.h>
#include <ipc/ipc.h>
#include <stddef.h>
#include <gui/gui.h>
#include <gui/api.h>
#include <ipc/signal.h>

// void _Handler(Sigaction sigaction) {
//     while(1) {
//         ;
//     }
//     void (*_fun)();
//     _fun = (void (*)())sigaction.handler;
//     _fun();
//     IPC_MSG sig_return = {
//         .src = -1,
//         .dst = -1,
//         .type = Signal,
//         .data = {SIG_RETURN}
//     };
//     send(&sig_return);
// }

void Test() {

    IPC_MSG msg = {
        .src = -1,
        .dst = 4,
        .type = P2P_A,
        .data = {0}
    };
    static int i=0, j=0;
    i++;j++;

    GUI *gui_data = msg.data;
    gui_data->type = Button;
    gui_data->data[0] = 250 + i*5;
    gui_data->data[1] = 250 + j*5;
    send(&msg);

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

    msg.data[1] = btn;
    msg.data[2] = Handler;
    msg.data[3] = Test;

    send(&msg);



    int j=0;
    j++;
    while(1) {
        for(int i = 0; i < 100000; i++)
            j++
            ;

    }
}