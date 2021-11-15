/**
 * @file kernel.c
 * @author TheAirBlow <pilexet.danila@gmail.com>
 * @brief Main kernel file
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#include "kernel.h"

/**
 * @brief Entrypoint
 */
void _start(KernelData data) {
    gop_init(data.framebuffer, data.font);
    print(0xFFFFFF, "GOP Implementation working\nNewline\n\nTwo newlines");
    while(1);
}