
#ifndef GUI_API_H
#define GUI_API_H

#include<ipc/ipc.h>
#include<gui/gui.h>



int lv_textarea_create_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_S, /* point 2 point */
        .data = {Function /* type of data */, 0 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



int lv_obj_set_y_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_A, /* point 2 point */
        .data = {Function /* type of data */, 1 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



int lv_btn_create_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_S, /* point 2 point */
        .data = {Function /* type of data */, 2 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



int lv_obj_set_x_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_A, /* point 2 point */
        .data = {Function /* type of data */, 3 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



int lv_label_create_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_S, /* point 2 point */
        .data = {Function /* type of data */, 4 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



int lv_win_create_c(int arg_0,int arg_1)
{
    IPC_MSG msg = {
        .src  = -1,
        .dst  = 4,
        .type = P2P_S, /* point 2 point */
        .data = {Function /* type of data */, 5 /* index of func */,2 /* # of Args */, arg_0, arg_1}
    };
    return send(&msg);
}



#endif

