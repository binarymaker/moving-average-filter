
/**
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  */

#ifndef BM_fd93dda4_8032_11e9_8713_c8ff28b6c6d9
#define BM_fd93dda4_8032_11e9_8713_c8ff28b6c6d9

/**
 * @file utility.h
 * @author binary maker <https://github.com/binarymaker>
 * @brief commonly used functions
 * @date 2019-05-27
 */
#include "stdint.h"
#include "stdlib.h"
#include "math.h"

typedef enum bit
{
  LOW = 0,
  HIGH
} bit_t;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(n) ((n < 0) ? (-n) : (n))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define POW2(x) (1 << (x))

#define BYTE_LOW(x) (x & 0x00FF)
#define BYTE_HIGH(x) ((x >> 8) & 0x00FF)
#define BIT_READ(x, bit) ((x >> bit) & 0x01)
#define BIT_SET(x, bit) (x | (1 << bit))
#define BIT_CLEAR(x, bit) (x & ~(1 << bit))
#define BIT_MASK(bit) (1 << bit)

int32_t scale(int32_t value, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
int32_t constrain(int32_t value, int32_t min, int32_t max);
int32_t smooth(int32_t input, float filter_level, int32_t prev_smoothed);
int32_t random(int32_t min, int32_t max);

#endif // BM_fd93dda4_8032_11e9_8713_c8ff28b6c6d9
