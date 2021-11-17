/**
 * @file gop.c
 * @author TheAirBlow <theairblow-help@gmail.com>
 * @brief GOP drawing code
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */

#include "gop.h"

struct stivale2_struct_tag_framebuffer* framebuffer;
Point cursorpos;

/**
 * @brief Initialize GOP
 * 
 * @param framebuffer Framebuffer
 * @param fnt PSF1 Font
 */
void gop_init(struct stivale2_struct_tag_framebuffer* fb) {
    framebuffer = fb;
    clear(0x000000);
}

/**
 * @brief Draws a filled rectangle
 * 
 * @param x X position
 * @param y Y position
 * @param w Width
 * @param h Height
 * @param color 32-bit RGB color
 */
void draw_filled_rectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
    for (uint32_t i = x; i < x + w; i++)
    for (uint32_t j = y; j < y + h; j++)
        draw_pixel(i, j, color);
}

/**
 * @brief Clears the screen
 * 
 * @param color 32-bit RGB color
 */
void clear(uint32_t color) {
    draw_filled_rectangle(0, 0, framebuffer->framebuffer_width, framebuffer->framebuffer_height, color);
    cursorpos.x = 0;
    cursorpos.y = 0;
}

/**
 * @brief Draw a pixel
 * 
 * @param x X position
 * @param y Y position
 * @param pixel 32-bit RGB color
 */
void draw_pixel(uint32_t x, uint32_t y, uint32_t pixel) {
   *((uint32_t*)(framebuffer->framebuffer_addr + 4 * y + 4 * x)) = pixel;
}

/**
 * @brief Get a pixel's color
 * 
 * @param x X position
 * @param y Y position
 * @return 32-bit RGB color
 */
uint32_t get_pixel(uint32_t x, uint32_t y) {
   return *((uint32_t*)(framebuffer->framebuffer_addr + 4 * y + 4 * x));
}