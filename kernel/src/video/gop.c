#include <video/gop.h>
#include <lib/stdlib.h>

Framebuffer* framebuffer;
Point cursorpos;
PSF1_FONT* font;

void gopinit(Framebuffer* framebufferNew, PSF1_FONT* fontNew) {
    framebuffer = framebufferNew;
    font = fontNew;
    cursorpos.x = 0;
    cursorpos.y = 0;
}

void drawpixel(uint32_t x, uint32_t y, unsigned int color){
    *(uint32_t*)((uint64_t)framebuffer->BaseAddress + (x*4) + (y * framebuffer->PixelsPerScanLine * 4)) = color;
}

uint32_t getpixel(uint32_t x, uint32_t y){
    return *(uint32_t*)((uint64_t)framebuffer->BaseAddress + (x*4) + (y * framebuffer->PixelsPerScanLine * 4));
}

void drawline(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, unsigned int color) {
    for (uint32_t x = x1; x < x2; x++)
        for (uint32_t y = y1; y < y2; y++) {
            drawpixel(x, y, color);
        }
}

void drawrectangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t width, unsigned int color) {
    drawline(x1, y1, x1, y2 + width, color);
    drawline(x1, y1, x2 + width, y1, color);
    drawline(x2, y1 + width, x2, y2, color);
    drawline(x1 + width, y2, x2, y2, color);
}

void drawprogressbar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t width, unsigned int progress, unsigned int color, 
    unsigned int donecolor, unsigned int notdonecolor) {
    drawrectangle(x1, x1, x2, y2, width, color);
    int centerY = (y2-y1)/2;
    int lengthX = x2-x1-(width*2);
    int lengthForDone = lengthX / progress;
    int lengthForNotDone = lengthX - lengthForDone;
    drawline(x1 + width*2, centerY, x1 + lengthForDone, centerY, donecolor);
    drawline(x1 + lengthForDone, centerY, x1 + lengthForDone + lengthForNotDone, centerY, notdonecolor);
}

void putchar(unsigned int color, char chr, uint32_t xOff, uint32_t yOff) {
    unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
    char* fontPtr = font->glyphBuffer + (chr * font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++){
        for (unsigned long x = xOff; x < xOff+8; x++){
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                    *(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanLine)) = color;
                }

        }
        fontPtr++;
    }
}

void print(unsigned int color, char* str) {
    char* chr = str;
    while(*chr != 0){
        if (*chr == 10) {
            newline();
        } else {
            putchar(color, *chr, cursorpos.x, cursorpos.y);
            cursorpos.x += 8;
            if(cursorpos.x + 8 > framebuffer->Width) {
                cursorpos.x = 0;
                cursorpos.y += 18;
            }
        }

        chr++;
    }
}

void printpos(unsigned int color, char* str, uint32_t x, uint32_t y) {
    char* chr = str;
    while(*chr != 0){
        Point pos;
        pos.x = x;
        pos.y = y;
        if (*chr == 10) {
            pos.x = 10;
            pos.y += 16;
            continue;
        }
        putchar(color, *chr, pos.x, pos.y);
        pos.x += 8;
        if(pos.x + 8 > framebuffer->Width) {
            pos.x = 0;
            pos.y += 18;
        }
        chr++;
    }
}


void clear() {
    uint64_t fbBase = (uint64_t)framebuffer->BaseAddress;
    uint64_t bytesPerScanline = framebuffer->PixelsPerScanLine * 4;
    uint64_t fbHeight = framebuffer->Height;
    uint64_t fbSize = framebuffer->BufferSize;

    for (int verticalScanline = 0; verticalScanline < fbHeight; verticalScanline ++){
        uint64_t pixPtrBase = fbBase + (bytesPerScanline * verticalScanline);
        for (uint32_t* pixPtr = (uint32_t*)pixPtrBase; pixPtr < (uint32_t*)(pixPtrBase + bytesPerScanline); pixPtr ++){
            *pixPtr = 0xFFFFFF;
        }
    }
}

void newline(){
    cursorpos.x = 0;
    cursorpos.y += 16;
}

