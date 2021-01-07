//
// Created by wang_shuai on 2021/1/5.
//
// GUI service to help other process create avaliable graphics

#include "stdio.h"
#include <gui/gui.h>
#include "./lvgl/lvgl.h"

static uint32_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10]; /*Declare a buffer for 1/10 screen size*/


static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    printf("()");
    // static uint32_t flush_buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];
    // for(int i = area->x1 , k = 0;i <= area->x2; i++) {
    //     for(int j = - area->y1; j <= area->y2; j++) {
    //         flush_buf[k++] = color_p->full;
    //     }
    // }
    struct ROI roi = {
        .x1 = area->x1,
        .x2 = area->x2,
        .y1 = area->y1,
        .y2 = area->y2,
        .color = (Color*) color_p
    };
    //GraphFlush(&roi);
    lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
}




void main(int arg,char *argv[])
{
    int stdin = open("dev_tty0",O_RDWR);
    int stdout= open("dev_tty0",O_RDWR);
    int stderr= open("dev_tty0",O_RDWR);

    //get_ticks();

    printf("o");
    
//   {
//
//   }
    InitLvFontMontserrat_14();
    lv_init();

    static lv_disp_buf_t disp_buf;
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

    lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
    disp_drv.flush_cb = my_disp_flush;    /*Set your driver function*/
    disp_drv.buffer = &disp_buf;          /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/



//   lv_obj_t * label;
lv_obj_t * win = lv_win_create(lv_scr_act(), NULL);
   lv_win_set_title(win, "Window title");     
   


   lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
//    label = lv_label_create(btn1, NULL);
//    lv_label_set_text(label, "Button");

   lv_obj_set_x(btn1, 50);
   lv_obj_set_y(btn1, 50);

   lv_obj_set_size(btn1, 100, 50);

//    lv_slider_set_value(btn1, 70, LV_ANIM_ON);

    
//   label = lv_label_create(btn1, NULL);
//   lv_label_set_text(label, "Button");

    // while(1) {
    //     lv_tick_inc(10);
    //     printf("**==op");
    //     lv_task_handler();
    // }
    // flush(1, 2, 3, 4, 5);

//    printf("o");
//    static uint32_t col[640*480] = {0};
//
//    for(int i=0; i<640*480; i++)
//    {
//        col[i] = 0xffff;
//    }
////
////
////    //uint32_t col = 0x0000ffff;
//    struct ROI roi = {
//        .x1 = 600,
//        .x2 = 640,
//        .y1 = 440,
//        .y2 = 480,
//        .color = (Color*) col
//    };
//    GraphFlush(&roi);

    while (1)
    {
        /* code */
        // lv_tick_inc(10);
        lv_task_handler();
    }
    
    return ;
}

