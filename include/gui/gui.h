//
// Created by wang_shuai on 2021/1/5.
//

#ifndef MINIOS_LVGL_PORTING_GUI_H
#define MINIOS_LVGL_PORTING_GUI_H

#include "const.h"
#include "type.h"


#include <stdint.h>
#include <gui/gui.h>

typedef struct Color{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
}Color;

typedef struct ROI{

    int x1,y1,x2,y2;
    Color* color;
}ROI;


void GraphFlush(ROI*);

enum GUI_Type{
    Keyboard,
    Mouse,

    Button,
    Window,

    Function,

    RegisterCallback,
};

typedef struct {
    int type;
    int data[5];
}GUI;


#endif //MINIOS_LVGL_PORTING_GUI_H
