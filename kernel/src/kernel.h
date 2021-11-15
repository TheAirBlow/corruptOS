/**
 * @file kernel.h
 * @author TheAirBlow <pilexet.danila@gmail.com>
 * @brief Kernel header file
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#pragma once
#include <stdint.h>
#include <video/psf.h>
#include <video/gop.h>

/**
 * @brief Structure with useful stuff
 */
typedef struct {
    Framebuffer* framebuffer;
    PSF1_FONT* font;
    uint64_t kernelSize;
    void* kernelStart;
    void* kernelEnd;
} KernelData;