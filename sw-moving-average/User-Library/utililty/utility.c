
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

#include "utility.h"

int32_t scale(int32_t value,
              int32_t in_min,
              int32_t in_max,
              int32_t out_min,
              int32_t out_max)
{
  return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int32_t constrain(int32_t value,
                  int32_t min,
                  int32_t max)
{
  int limit;

  if (value < min)
  {
    limit = min;
  }
  else if (value > max)
  {
    limit = max;
  }
  else
  {
    limit = value;
  }

  return limit;
}

int32_t smooth(int32_t input,
               float filter_level,
               int32_t prev_smoothed)
{
  if (filter_level > 1)
  {
    filter_level = 0.99;
  }
  else if (filter_level <= 0)
  {
    filter_level = 0.0;
  }
  
  return (input * (1 - filter_level)) + (prev_smoothed * filter_level);
}


int32_t random(int32_t min,
               int32_t max)
{
  return (rand() % (max + 1 - min)) + min;
}
