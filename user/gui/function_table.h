
#ifndef GUI_SERVER_FUNCTION_H
#define GUI_SERVER_FUNCTION_H

#include <gui/gui.h>
#include "./lvgl/lvgl.h"

void* FunctionTable[] = {
    lv_win_create,
lv_textarea_create,
lv_obj_set_x,
lv_btn_create,
lv_label_create,
lv_obj_set_y
};


#endif

