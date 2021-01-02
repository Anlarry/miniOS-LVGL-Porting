#include <gui/gui.h>
#include <gui/vbe.h>
#include <gui/lvgl/lvgl.h>
#include <gui/lvgl/src/lv_misc/lv_gc.h>

static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    int32_t x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            // set_pixel(x, y, *color_p);  /* Put a pixel to the display.*/
            // PlotPixel(x, y, 
            //     (color_p->ch.red << 5) + (color_p->ch.green << 2) + (color_p->ch.blue)
            // );
            color_p++;
        }
    }

    lv_disp_flush_ready(disp);         /* Indicate you are ready with the flushing*/
}

void InitScreen() {
    // for(int i = )
    for(int i = VRAM_START; i < VRAM_END; i++) {
        PlotAddr(i, 15);
    }
    for(int x = 0; x < 100; x++) {
        for(int y = 0; y < 50; y++) {
            PlotPixel(x, y, 21);
        }
    }
    for(int x = 50; x < 150; x++) {
        for(int y = 25; y < 75; y++) {
            PlotPixel(x, y, 105);
        }
    }


    lv_init();
    static lv_disp_buf_t disp_buf;
    static lv_color_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];                     /*Declare a buffer for 1/10 screen size*/
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);    

    lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
    disp_drv.flush_cb = my_disp_flush;    /*Set your driver function*/
    disp_drv.buffer = &disp_buf;          /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/



    while(1) {
        // for(int i = 0; i < 100000; i++);
        // for(int i = 0; i < 5; i++)
        lv_tick_inc(10);
        lv_task_handler();
    }
}






