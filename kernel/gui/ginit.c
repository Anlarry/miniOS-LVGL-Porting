#include <gui/gui.h>
// #include <gui/vbe.h>
// #include <gui/lvgl/lvgl.h>
// #include <gui/lvgl/src/lv_misc/lv_gc.h>

void sys_flush(ROI* roi)
{
        int x1 = roi->x1;
        int y1 = roi->y1;
        int x2 = roi->x2;
        int y2 = roi->y2;

       disp_str("in");
       disp_int(x1);
       disp_int(y1);
       disp_int(x2);
       disp_int(y2);
//        disp_int(roi->color);
//        for(int i=0xfd000000; i<0xfdffffff; i++)
//        {
//            char *ptr;
//            ptr = i;
//            *ptr = 0;
//        }


//        for(int i = 0; i < SCRNX; i++) {
//        for(int j = 0; j < SCRNY; j++) {
//            PlotPixel(i, j, 0xff, 0xff, 0);
//        }
//        }
//    for(int i=x1; i<x2; i++)
//    {
//        for(int j=y1; j<y2; j++)
//        {
//            //PlotPixel(i, j, colors->red, colors->green, colors->blue);
//            PlotPixel(i,j,100,100,0);
//            colors++;
//        }
//    }
}


// static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
// {
//     int32_t x, y;
//     for(y = area->y1; y <= area->y2; y++) {
//         for(x = area->x1; x <= area->x2; x++) {
//             // set_pixel(x, y, *color_p);  /* Put a pixel to the display.*/
//             PlotPixel(x, y,
//                 color_p->ch.red, color_p->ch.green, color_p->ch.blue
//             );
//             color_p++;
//         }
//     }
//     lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
// }

// void InitScreen() {
//     // for(int i = )
//     // for(int i = VRAM_START; i < VRAM_END; i++) {
//     //     PlotAddr(i, 15);
//     // }
//     // for(int x = 0; x < 100; x++) {
//     //     for(int y = 0; y < 50; y++) {
//     //         PlotPixel(x, y, 21);
//     //     }
//     // }
//     // for(int x = 50; x < 150; x++) {
//     //     for(int y = 25; y < 75; y++) {
//     //         PlotPixel(x, y, 105);
//     //     }
//     // }

// //    for(int i = 0; i < SCRNX; i++) {
// //        for(int j = 0; j < SCRNY; j++) {
// //            PlotPixel(i, j, 0xff, 0xff, 0);
// //        }
// //    }

//     InitLvFontMontserrat_14();

//     lv_init();

//     static lv_disp_buf_t disp_buf __DATA__;
//     static lv_color_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10]; /*Declare a buffer for 1/10 screen size*/
//     lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

//     lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
//     lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
//     disp_drv.flush_cb = my_disp_flush;    /*Set your driver function*/
//     disp_drv.buffer = &disp_buf;          /*Assign the buffer to the display*/
//     lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/

//     lv_obj_t * label;

//     lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
//     // label = lv_label_create(btn1, NULL);
//     // lv_label_set_text(label, "Button");

//     lv_obj_set_x(btn1, 30);
//     lv_obj_set_y(btn1, 10);
//     lv_obj_set_size(btn1, 200, 50);
//     lv_slider_set_value(btn1, 70, LV_ANIM_ON);

//     label = lv_label_create(btn1, NULL);
//     lv_label_set_text(label, "Button");

// //    lv_obj_t * win = lv_win_create(lv_scr_act(), NULL);
// //    lv_win_set_title(win, "Window title");

//     while(1) {
//         // for(int i = 0; i < 100000; i++);
//         // for(int i = 0; i < 5; i++)
//         lv_tick_inc(10);
//         lv_task_handler();
//     }
// }






