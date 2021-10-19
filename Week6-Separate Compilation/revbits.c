/**
 * @file revbits.c
 * @author Hengyi Li
 * @brief This file is to mirror reverse the bits
 * @version 0.1
 * @date 2021-10-15 11:26 PM
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved
 */

#include <stdint.h>
#include "revbits.h"

uint8_t revbits8(uint8_t value)
{
  uint8_t result = 0;
  uint8_t mask = 0x80;

  /* As long as the value is not negative or 0 */
  while (value > 0)
  {
    /* 0 shift the bits, 1 compare the result with the mask*/
    if (value % 2 == 1)
    {
      result |= mask;
    }
    value >>= MOVE_ONE_BITS;
    mask >>= MOVE_ONE_BITS;
  }
  return result;
}

uint16_t revbits16(uint16_t value)
{
  uint16_t result = 0;
  uint16_t mask = 0x8000;
  /* As long as the value is not negative or 0 */
  while (value > 0)
  {
    /* 0 shift the bits, 1 compare the result with the mask*/
    if (value % 2 == 1)
    {
      result |= mask;
    }
    value >>= MOVE_ONE_BITS;
    mask >>= MOVE_ONE_BITS;
  }
  return result;
}
