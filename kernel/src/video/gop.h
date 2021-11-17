/**
 * @file gop.h
 * @author TheAirBlow <theairblow-help@gmail.com>
 * @brief GOP C header
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#pragma once
#include <stddef.h>
#include <stdint.h>
#include "psf.h"
#include <stivale2.h>

/**
 * @brief X and Y pair
 */
typedef struct {
    uint32_t x;
    uint32_t y;
} Point;

void clear(uint32_t color);
void gop_init(struct stivale2_struct_tag_framebuffer* fb);
void draw_pixel(uint32_t x, uint32_t y, uint32_t pixel);
uint32_t get_pixel(uint32_t x, uint32_t y);
void draw_filled_rectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
void print_character(uint32_t x, uint32_t y, const char chr, uint32_t color);
void print_position(uint32_t color, char* str, Point* pos);
void print(uint32_t color, char* str);
void newline_point(Point* pos);
void newline();