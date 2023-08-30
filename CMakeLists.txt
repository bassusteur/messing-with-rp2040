cmake_minimum_required(VERSION 3.15...3.25)

#set(CMAKE_TOOLCHAIN_FILE ./toolchain-arm.cmake)

include(pico_sdk_import.cmake)

include(pico_extras_import_optional.cmake)

project(armtest VERSION 0.1 LANGUAGES C CXX ASM)

pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        -g
        )


add_executable(armtest main.c)

target_link_libraries(armtest pico_stdlib)

pico_enable_stdio_usb(armtest 1)
pico_enable_stdio_uart(armtest 1)

pico_add_extra_outputs(armtest)
