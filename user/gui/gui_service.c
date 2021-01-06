//
// Created by wang_shuai on 2021/1/5.
//
// GUI service to help other process create avaliable graphics

#include "stdio.h"
#include "../include/gui/gui.h"
#include "./lvgl/lvgl.h"

static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    printf("()");
    flush(area->x1, area->y1, area->x2, area->y2, (char*)color_p);
    lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
}


void main(int arg,char *argv[])
{
    int stdin = open("dev_tty0",O_RDWR);
    int stdout= open("dev_tty0",O_RDWR);
    int stderr= open("dev_tty0",O_RDWR);

    //get_ticks();

    char buff[1024];
    int pid;
    int times = 0;

    char temp[2501] = {0};
    while(1)flush(0,0, 50,50, temp);
    InitLvFontMontserrat_14();
    lv_init();
    printf("o");

    static lv_disp_buf_t disp_buf;
    static lv_color_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10]; /*Declare a buffer for 1/10 screen size*/
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

    lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
    // disp_drv.flush_cb = my_disp_flush;    /*Set your driver function*/
    disp_drv.buffer = &disp_buf;          /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/

//    lv_obj_t * label;
//
//    lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
//    // label = lv_label_create(btn1, NULL);
//    // lv_label_set_text(label, "Button");
//
//    lv_obj_set_x(btn1, 30);
//    lv_obj_set_y(btn1, 10);
//    lv_obj_set_size(btn1, 200, 50);
//    lv_slider_set_value(btn1, 70, LV_ANIM_ON);

//    label = lv_label_create(btn1, NULL);
//    lv_label_set_text(label, "Button");

    while(1) {
        lv_tick_inc(10);
        printf("**==op");
        lv_task_handler();
    }

    return ;
}

static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    flush(area->x1, area->y1, area->x2, area->y2, (char*)color_p);
    lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
}
