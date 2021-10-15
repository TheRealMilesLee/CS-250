#include <stdint.h>
#include <stdio.h>
#include "revbits.h"

uint8_t revbits8(uint8_t value)
{
  uint8_t result = 0;
  uint8_t mask = 0x80;

  while (value > 0)
  {
    if (value % 2 == 1)
    {
      result |= mask;
    }
    value >>= 1;
    mask >>= 1;
  }
  return result;
}

/* TODO: Copy and modify revbits8 to make it work in revbits16 */
uint16_t revbits16(uint16_t value)
{
  uint16_t result = 0;
  uint16_t mask = 0x8000;
  while (value > 0)
  {
    if (value % 2 == 1)
    {
      result |= mask;
    }
    value >>= 1;
    mask >>= 1;
  }  
  return result;
}
