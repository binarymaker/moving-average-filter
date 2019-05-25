
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

#ifndef BM_e1b20914_7abb_11e9_af78_c8ff28b6c6d9
#define BM_e1b20914_7abb_11e9_af78_c8ff28b6c6d9

/**
 * @file moving-average.h
 * @author binary maker <https://github.com/binarymaker>
 * @brief Average filter based on FIFO buffer
 * @date 2019-05-25
 *
 */

/* 
                             input
                               +
                               |
                               v
            +------------------+--------------------+
  index +-->+                 DEMUX                 |
            +----+------+------+----------------+---+
                 |      |      |                |
              +--+-+ +--+-+ +--+-+           +--+-+
              | B0 | | B1 | | B3 | . . . . . | Bn |   <- buffer
              +-+--+ +-+--+ +-+--+           +-+--+      n is size-1
                |      |      |                |
            +---+------+------+----------------+----+
            |              ACCUMULATOR              |
            +------------------+--------------------+
                               | <---------------------- sum
                               v
                      +--------+--------+
                      | divided by fill |
                      +--------+--------+
                               |
                               v
                            filtered
                             result
 */

#include "stdint.h"

typedef struct movingAverage_s
{
  int16_t *buffer;  /**< Data buffer pointer */
  uint16_t size;    /**< Size of filter buffer */
  uint16_t index;   /**< Current location in buffer */
  uint16_t fill;    /**< Buffer filled level */
  int32_t sum;      /**< Cumulative value of buffer */
  int16_t filtered; /**< Filtered output */
} movingAverage_t;

/**
 * @brief filter object initialization
 * 
 * @param context [in] instance of filter object
 * @param filter_size [in] size of filter buffer
 */
void moving_average_create(movingAverage_t *context, uint16_t filter_size);

/**
 * @brief filter process function
 * 
 * @param context [in] instance of filter object
 * @param input [in] data sample to filter
 */
void moving_average_filter(movingAverage_t *context, int16_t input);

#endif // BM_e1b20914_7abb_11e9_af78_c8ff28b6c6d9
