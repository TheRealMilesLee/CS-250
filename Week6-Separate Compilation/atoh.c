#include <stdio.h>
#include <stdint.h>
#include "atoh.h"

uint8_t atoh8(const char* string)
{
  char value = '\0';
  uint8_t result = '\0';
  if (isdigit(string[HEX_CHARACTER_PLACE]) && 
  isdigit(string[NEXT_HEX_CHARACTER_PLACE]))
  {
    value = string[HEX_CHARACTER_PLACE] - '0';
    value <<= MOVE_FOUR_BIT_FOR_PLACE;
    value += string[NEXT_HEX_CHARACTER_PLACE] - '0';
  }
  else if (isdigit(string[HEX_CHARACTER_PLACE]) && 
  !isdigit(string[NEXT_HEX_CHARACTER_PLACE]))
  {
    value = string[HEX_CHARACTER_PLACE];
    value <<= MOVE_FOUR_BIT_FOR_PLACE;
    value += (string[NEXT_HEX_CHARACTER_PLACE] - 'a' + 0xA);
  }
  else if (!isdigit(string[HEX_CHARACTER_PLACE]) && 
  isdigit(string[NEXT_HEX_CHARACTER_PLACE]))
  {
    value = (string[HEX_CHARACTER_PLACE] - 'a' + 0xA);
    value <<= MOVE_FOUR_BIT_FOR_PLACE;
    value += string[NEXT_HEX_CHARACTER_PLACE] - '0';
  }
  else
  {
    value = (string[HEX_CHARACTER_PLACE] - 'a' + 0xA);
    value <<= MOVE_FOUR_BIT_FOR_PLACE;
    value += (string[NEXT_HEX_CHARACTER_PLACE] - 'a' + 0xA);
  }
  result = (uint8_t)value;
  return result;
}

uint16_t atoh16(const char* string)
{
  char value = '\0';
  uint16_t result = '\0';
    if (isdigit(string[2]) && isdigit(string[3]) && isdigit(string[4]) && isdigit(string[5]))
    {
      value = string[2] - '0';
      value <<= 8;
      value += string[3] - '0';
      value <<= 4;
      value += string[4] -'0';
      value <<= 4;
      value += string[5] - '0';
    }
    else if (!isdigit(string[2]) && isdigit(string[3]) && isdigit(string[4]) && isdigit(string[5]))
    {
      value = (string[2] - 'a' + 0xA);
      value <<= 8;
      value += string[3] - '0';
      value <<= 4;
      value += string[4] -'0';
      value <<= 4;
      value += string[5] - '0';
    }
    else if (isdigit(string[2]) && !isdigit(string[3]) && isdigit(string[4]) && isdigit(string[5]))
    {
      value = string[2] - '0';
      value <<= 8;
      value += (string[3] - 'a' + 0xA);
      value <<= 4;
      value += string[4] -'0';
      value <<= 4;
      value += string[5] - '0';
    }
    else
    {
      value = (string[2] - 'a' + 0xA);
      value <<= 8;
      value += (string[3] - 'a' + 0xA);
      value <<= 4;
      value += (string[4] -'a' + 0xA);
      value <<= 4;
      value += (string[5] - 'a' + 0xA);
    }
    result = (uint16_t)value;
    return result;
}