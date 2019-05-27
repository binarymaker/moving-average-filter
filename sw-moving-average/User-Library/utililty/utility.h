
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

/**
 * @brief Byte and Bit access 
 * 
 */
#define BYTE_LOW(x) (x & 0x00FF)
#define BYTE_HIGH(x) ((x >> 8) & 0x00FF)
#define BIT_READ(x, bit) ((x >> bit) & 0x01)
#define BIT_SET(x, bit) (x | (1 << bit))
#define BIT_CLEAR(x, bit) (x & ~(1 << bit))
#define BIT_MASK(bit) (1 << bit)

/**
 * @brief Resize the value 
 * 
 * @param value [in] input value have to change
 * @param in_min [in] minimum value of input
 * @param in_max [in] maximum value of input
 * @param out_min [in] minimum value of output
 * @param out_max [in] maximum value of output
 * @return int32_t [out] resized output value
 */
int32_t
scale(int32_t value, int32_t in_min, int32_t in_max,
      int32_t out_min, int32_t out_max);

/**
 * @brief Limit data/value range 
 * 
 * @param [in] value have to limit
 * @param min [in] minimum value of limit
 * @param max [in] maximum value of limit
 * @return int32_t [out] Limited output value
 */
int32_t
constrain(int32_t *value, int32_t min, int32_t max);

/**
 * @brief simple filter for smooth sequence data
 * 
 * @param input [in] Filter input
 * @param filter_level [in] Filter % value 
 *                          range 0.00 to 1.0. 
 *                          0.0 - low filter
 *                          0.5 - medium filter
 *                          1.0 - Heavy filter
 * @param prev_smoothed [in] Last output value of smooth filter
 * @return int32_t [out] Smoothed filter output
 */
int32_t
smooth(int32_t input, float filter_level, int32_t prev_smoothed);

/**
 * @brief Generate random number with in limit
 * 
 * @param min [in] Minimum value of ramdom number
 * @param max [in] Maximum value of ramdom number
 * @return int32_t [in] Ramdom value output
 */
int32_t
random(int32_t min, int32_t max);

#endif // BM_fd93dda4_8032_11e9_8713_c8ff28b6c6d9
