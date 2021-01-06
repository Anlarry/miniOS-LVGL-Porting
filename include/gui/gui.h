//
// Created by wang_shuai on 2021/1/5.
//

#ifndef MINIOS_LVGL_PORTING_GUI_H
#define MINIOS_LVGL_PORTING_GUI_H

#include "const.h"
#include "type.h"

typedef struct {
    int x1,y1,x2,y2;
    struct Color* color;
}ROI;

void flush(ROI*);

#endif //MINIOS_LVGL_PORTING_GUI_H
