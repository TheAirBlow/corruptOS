/**
 * @file mem.h
 * @author TheAirBlow (theairblow-help@gmail.com)
 * @brief Memory
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#pragma once
#include <stddef.h>

void memcpy(void* restrict dest, const void* restrict src, size_t count);
void memset(void* b, int val, size_t count);