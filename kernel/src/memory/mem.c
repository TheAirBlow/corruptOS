/**
 * @file mem.c
 * @author TheAirBlow (theairblow-help@gmail.com)
 * @brief Memory
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#include "mem.h"

/**
 * @brief Memory copy (no overlap)
 * 
 * @param dest Destination
 * @param src Source
 * @param count Size
 */
void memcpy(void* restrict dest, const void* restrict src, size_t count) {
	asm volatile ("cld; rep movsb" : "+c" (count), "+S" (src), "+D" (dest) :: "memory");
	return dest;
}

/**
 * @brief Fill memory
 * 
 * @param b Destination
 * @param val Value
 * @param count Size
 */
void memset(void* b, int val, size_t count) {
	asm volatile ("cld; rep stosb" : "+c" (count), "+D" (b) : "a" (val) : "memory");
	return b;
}