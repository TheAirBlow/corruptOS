#pragma once
#include <lib/stdlib.h>

typedef struct {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} Framebuffer;

typedef struct {
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

typedef struct {
	PSF1_HEADER* psf1_Header;
	void* glyphBuffer;
} PSF1_FONT;

typedef struct {
    unsigned int x;
    unsigned int y;
} Point;

extern Point cursorpos;
extern void drawprogressbar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t width, unsigned int progress, 
	unsigned int color, unsigned int donecolor, unsigned int notdonecolor);
extern void drawrectangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t width, unsigned int color);
extern void drawline(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, unsigned int color);
extern void drawrectangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t width, unsigned int color);
extern void putchar(unsigned int color, char chr, uint32_t xOff, uint32_t yOff);
extern void printpos(unsigned int color, char* str, uint32_t x, uint32_t y);
extern void gopinit(Framebuffer* framebufferNew, PSF1_FONT* fontNew);
extern void drawpixel(uint32_t x, uint32_t y, unsigned int colour);
extern uint32_t getpixel(uint32_t x, uint32_t y);
extern void print(unsigned int color, char* str);
extern void clear();
extern void newline();