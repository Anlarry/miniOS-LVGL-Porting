import cv2

img = cv2.imread("./cursors32.png", cv2.IMREAD_UNCHANGED)

with open("./icon.c", "w") as file:
    file.write('#include "./lvgl/lvgl.h"\n')
    file.write("uint8_t my_img_data[{}]".format(int(img.shape[0]*img.shape[1]*4)))
    file.write("= {")
    # print(img.shape)
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            file.write("{},".format(img[i][j][0]))
            file.write("{},".format(img[i][j][1]))
            file.write("{},".format(img[i][j][2]))
            file.write("{},".format(img[i][j][3]))
            file.write("\n")
    file.write("};\n")
    file.write("lv_img_dsc_t my_img_dsc = { \n"
               ".header.always_zero = 0,\n"
               ".header.w = %d,\n"
               ".header.h = %d,\n"
               ".data_size = %d * %d * LV_COLOR_DEPTH / 8,\n"
               ".header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,          /*Set the color format*/\n"
               ".data = my_img_data,\n"
               "};\n"%(int(img.shape[1]), int(img.shape[0]), int(img.shape[1]), int(img.shape[0])))
