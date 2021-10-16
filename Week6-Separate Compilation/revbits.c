#include <stdint.h>
#include "revbits.h"

uint8_t revbits8(uint8_t value)
{
  uint8_t result = 0;
  uint8_t mask = 0x80;
  
  while (value > 0)
  {
    /* As long as the value is not negative or 0 */
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
    if (value % 2 == 1)
    {
      result |= mask;
    }
    value >>= MOVE_ONE_BITS;
    mask >>= MOVE_ONE_BITS;
  }
  return result;
}
