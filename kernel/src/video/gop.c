/**
 * @file gop.c
 * @author TheAirBlow <pilexet.danila@gmail.com>
 * @brief GOP drawing code
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */

#include "gop.h"

Framebuffer* framebuffer;
PSF1_FONT* font;
Point cursorpos;

/**
 * @brief Initialize GOP
 * 
 * @param framebuffer Framebuffer
 * @param fnt PSF1 Font
 */
void gop_init(Framebuffer* fb, PSF1_FONT* fnt) {
    framebuffer = fb;
    clear(0x000000);
    font = fnt;
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
    draw_filled_rectangle(0, 0, framebuffer->width, framebuffer->height, color);
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
   *((uint32_t*)(framebuffer->base + 4 * framebuffer->pps * y + 4 * x)) = pixel;
}

/**
 * @brief Get a pixel's color
 * 
 * @param x X position
 * @param y Y position
 * @return 32-bit RGB color
 */
uint32_t get_pixel(uint32_t x, uint32_t y) {
   return *((uint32_t*)(framebuffer->base + 4 * framebuffer->pps * y + 4 * x));
}

/**
 * @brief Print a character on position
 * 
 * @param x X position
 * @param y Y position
 * @param chr Character
 * @param color 32-bit RGB color 
 */
void print_character(uint32_t x, uint32_t y, const char chr, uint32_t color) {
    uint32_t* pixPtr = (uint32_t*)framebuffer->base;
    char* fontPtr = font->glyphBuffer + (chr * font->psf1_Header->charsize);
    for (uint32_t y2 = y; y2 < y + 16; y2++) {
        for (uint32_t x2 = x; x2 < x + 8; x2++) 
            if ((*fontPtr & (0b10000000 >> (x2 - x))) > 0)
                draw_pixel(x2, y2, color);
        fontPtr++;
    }
}

/**
 * @brief Do a newline on Point
 * 
 * @param pos Point
 */
void newline_point(Point* pos) {
    pos->x = 0;
    pos->y += 18;
}

/**
 * @brief Do a newline on `cursorpos`
 */
void newline() {
    cursorpos.x = 0;
    cursorpos.y += 18;
}

/**
 * @brief Print zero-terminated string on position 
 * 
 * @param color 32-bit RGB color
 * @param str Pointer
 * @param pos Point
 */
void print_position(uint32_t color, char* str, Point* pos) {
    char* chr = str;
    while(*chr != 0){
        if (*chr == 10) {
            newline_point(pos);
            chr++;
            continue;
        }
        print_character(pos->x, pos->y, *chr, color);
        if(pos->x + 8 > framebuffer->width)
            newline_point(pos);
        else pos->x += 8;
        chr++;
    }
}

/**
 * @brief Print zero-terminated string on `cursorpos` 
 * 
 * @param color 32-bit RGB color
 * @param str Pointer
 */
void print(uint32_t color, char* str) {
    print_position(color, str, &cursorpos);
}