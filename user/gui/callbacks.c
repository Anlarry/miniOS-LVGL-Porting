
#include <stdint.h>
#include <ipc/ipc.h>
#include <gui/lvgl/lvgl.h>

#include "callbacks.h"

int _call_back_num = 0;
int _max_call_back = 30;


uint32_t _Handler[30];
uint32_t _Test[30];
uint32_t _dst[30];


void CallBack_0(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[0],
        .type = Signal,
        .data = {SIG_SEND, _Handler[0], _Test[0]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_1(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[1],
        .type = Signal,
        .data = {SIG_SEND, _Handler[1], _Test[1]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_2(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[2],
        .type = Signal,
        .data = {SIG_SEND, _Handler[2], _Test[2]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_3(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[3],
        .type = Signal,
        .data = {SIG_SEND, _Handler[3], _Test[3]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_4(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[4],
        .type = Signal,
        .data = {SIG_SEND, _Handler[4], _Test[4]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_5(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[5],
        .type = Signal,
        .data = {SIG_SEND, _Handler[5], _Test[5]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_6(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[6],
        .type = Signal,
        .data = {SIG_SEND, _Handler[6], _Test[6]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_7(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[7],
        .type = Signal,
        .data = {SIG_SEND, _Handler[7], _Test[7]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_8(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[8],
        .type = Signal,
        .data = {SIG_SEND, _Handler[8], _Test[8]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_9(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[9],
        .type = Signal,
        .data = {SIG_SEND, _Handler[9], _Test[9]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_10(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[10],
        .type = Signal,
        .data = {SIG_SEND, _Handler[10], _Test[10]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_11(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[11],
        .type = Signal,
        .data = {SIG_SEND, _Handler[11], _Test[11]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_12(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[12],
        .type = Signal,
        .data = {SIG_SEND, _Handler[12], _Test[12]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_13(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[13],
        .type = Signal,
        .data = {SIG_SEND, _Handler[13], _Test[13]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_14(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[14],
        .type = Signal,
        .data = {SIG_SEND, _Handler[14], _Test[14]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_15(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[15],
        .type = Signal,
        .data = {SIG_SEND, _Handler[15], _Test[15]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_16(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[16],
        .type = Signal,
        .data = {SIG_SEND, _Handler[16], _Test[16]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_17(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[17],
        .type = Signal,
        .data = {SIG_SEND, _Handler[17], _Test[17]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_18(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[18],
        .type = Signal,
        .data = {SIG_SEND, _Handler[18], _Test[18]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_19(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[19],
        .type = Signal,
        .data = {SIG_SEND, _Handler[19], _Test[19]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_20(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[20],
        .type = Signal,
        .data = {SIG_SEND, _Handler[20], _Test[20]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_21(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[21],
        .type = Signal,
        .data = {SIG_SEND, _Handler[21], _Test[21]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_22(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[22],
        .type = Signal,
        .data = {SIG_SEND, _Handler[22], _Test[22]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_23(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[23],
        .type = Signal,
        .data = {SIG_SEND, _Handler[23], _Test[23]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_24(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[24],
        .type = Signal,
        .data = {SIG_SEND, _Handler[24], _Test[24]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_25(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[25],
        .type = Signal,
        .data = {SIG_SEND, _Handler[25], _Test[25]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_26(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[26],
        .type = Signal,
        .data = {SIG_SEND, _Handler[26], _Test[26]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_27(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[27],
        .type = Signal,
        .data = {SIG_SEND, _Handler[27], _Test[27]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_28(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[28],
        .type = Signal,
        .data = {SIG_SEND, _Handler[28], _Test[28]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}


void CallBack_29(lv_obj_t * obj, lv_event_t event)
{
    IPC_MSG sig_test = {
        .src = -1,
        .dst = _dst[29],
        .type = Signal,
        .data = {SIG_SEND, _Handler[29], _Test[29]}
    }; 
    send(&sig_test);
    
    // switch(event) {
    //     case LV_EVENT_CLICKED : 
    //         send(&sig_test);
    //         break;
    // }
}



void* CallBackTable[] = {

CallBack_0,
CallBack_1,
CallBack_2,
CallBack_3,
CallBack_4,
CallBack_5,
CallBack_6,
CallBack_7,
CallBack_8,
CallBack_9,
CallBack_10,
CallBack_11,
CallBack_12,
CallBack_13,
CallBack_14,
CallBack_15,
CallBack_16,
CallBack_17,
CallBack_18,
CallBack_19,
CallBack_20,
CallBack_21,
CallBack_22,
CallBack_23,
CallBack_24,
CallBack_25,
CallBack_26,
CallBack_27,
CallBack_28,
CallBack_29 

};



