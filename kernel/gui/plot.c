#include "plot.h"
#include <protect.h>

// int static inline Coor2Addr(int x, int y){
//     return (x + y * SCRNX) * 3;
// }

// void inline PlotPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
//     uint8_t *p = Coor2Addr(x, y);
//     __asm__ (
//         "mov %1, %%fs:(%%edi)\n"
//         "inc %0\n"
//         "mov %2, %%fs:(%%edi)\n"
//         "inc %0\n"
//         "mov %3, %%fs:(%%edi)\n"
//         : 
//         : "D"(p), "r"(r), "r"(g), "r"(b)
//         : 
//     );
// }

// void inline PlotAddr(int addr, uint8_t color) {
//     __asm__ (
//         "mov %1, %%fs:(%%edi)\n"
//         : 
//         : "D"(addr), "r"(color)
//         : 
//     );
// }


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
    uint16_t ds = SELECTOR_GRAPH;
    uint16_t ds_old; 
    __asm__ __volatile__ (
        "mov %%ds, %0\n"
        : "=r"(ds_old)
        :
        :
    );
    __asm__ __volatile__ (
        "mov %%ax, %%ds\n"
        : 
        : "a"(ds)
        :
    );
    __asm__ __volatile__("mov %cr3, %eax");
    __asm__ __volatile__("push %eax");
    __asm__ __volatile__("mov $0x200000, %eax");
    __asm__ __volatile__("mov %eax, %cr3");

    uint8_t *p = 0;
    for(int i = 0; i < SCRNX; i++) {
        for(int j = 0; j < SCRNY; j++) {
            *p++ = 0xff;
            *p++ = 0xff;
            *p++ = 0;
        }
    }

    // for(int i = 0; i < SCRNX; i++) {
    //     for(int j = 0; j < SCRNY; j++) {
    //         uint8_t *p = Coor2Addr(j, i);
    //         __asm__ (
    //             "mov %1, %%fs:(%%edi)\n"
    //             "inc %0\n"
    //             "mov %2, %%fs:(%%edi)\n"
    //             "inc %0\n"
    //             "mov %3, %%fs:(%%edi)\n"
    //             : 
    //             : "D"(p), "r"(0xff), "r"(0xff), "r"(0)
    //             : 
    //         );
    //     }
    // }
    // __asm__ __volatile__ ("movl $0, %edi");
    // for(int i = 0; i < 0xffffff; i++) {
    //     __asm__ (
    //         "mov %0, %%fs:(%%edi)\n"
    //         "inc %%edi\n"
    //         "mov %1, %%fs:(%%edi)\n"
    //         "inc %%edi\n"
    //         "mov %2, %%fs:(%%edi)\n"
    //         "inc %%edi"
    //         : 
    //         : "r"(0xff), "r"(0xff), "r"(0)
    //         : 
    //     );
    // }

    __asm__ __volatile__("pop %eax");
    __asm__ __volatile__("mov %eax, %cr3");

    __asm__ __volatile__ (
        "mov %%ax, %%ds"
        : 
        : "a"(ds_old)
        :
    );



//
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