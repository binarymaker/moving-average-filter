
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

#include "moving-average.h"
#include <stdlib.h>

void
moving_average_create(movingAverage_t *context,
                      uint16_t filter_size)
{
  free(context->buffer);

  context->size = filter_size;
  context->buffer = (int16_t*)malloc(filter_size * sizeof(uint16_t));
  context->index = 0;
  context->sum = 0;
  context->fill = 0;
  context->filtered = 0;
}

void
moving_average_filter(movingAverage_t *context,
                      int16_t filter_input)
{
  if (context->fill)
  {
    context->sum -= context->buffer[context->index];
  }

  context->buffer[context->index] = filter_input;
  context->sum += context->buffer[context->index];

  context->index++;
  if (context->index >= context->size)
  {
    context->index = 0;
  }

  if (context->fill < context->size)
  {
    context->fill++;
  }

  context->filtered = (int16_t)(context->sum / context->fill);
}



