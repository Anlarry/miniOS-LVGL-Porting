
SET(CMAKE_C_COMPILER /usr/bin/gcc-7)
SET(CMAKE_CXX_COMPILER /usr/bin/g++-7)

project(lvgl)
file(GLOB_RECURSE SOURCES src/*.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -m32 -fno-builtin -fno-stack-protector")

add_library(lvgl ${SOURCES})

