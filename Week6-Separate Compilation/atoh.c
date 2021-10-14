#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
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
  uint16_t move_nibble = '\0';
  int index = 0;
  while(index < string.sizeof() - 1 )
  {
    move_nibble += hexdigit_converted(string[index]);
    index++;
    move_nibble <<= 4;
  }
  move_nibble += hexdigit_converted(string[5]);
  printf("the nibble moved is %hx \n", move_nibble);
  return move_nibble;
}

uint16_t hexdigit_converted(char digit)
{
  if(digit < 'a')
  {
    if(isupper(digit))
    {
      return (uint16_t)(digit - '7');
    }
    return (uint16_t)(digit -'0');
  }
  return (uint16_t)(digit - 'a' + 10);
}
