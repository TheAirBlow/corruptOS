/**
 * @file psf.h 
 * @author TheAirBlow <pilexet.danila@gmail.com>
 * @brief PSF1 stuff
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#pragma once

/**
 * @brief PSF1 Header
 */
typedef struct {
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

/**
 * @brief PSF1 Font
 */
typedef struct {
	PSF1_HEADER* psf1_Header;
	void* glyphBuffer;
} PSF1_FONT;