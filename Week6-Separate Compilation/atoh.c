
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "atoh.h"

uint8_t atoh8(const char* string)
{
  uint8_t result = '\0';
  int index = 0;
  while(index < 3)
  {
    if(!isalpha(string[index]) && !isdigit(string[index]) && string[index] > 'f')
    {
      return 0;
    }
    else
    {
      index++;
    }
  }
    result += hexdigit_converted_8bits(string[2]);
    if(string[3] != '\0')
    {
      result <<= 4;
      result += hexdigit_converted_8bits(string[3]);
    }
  printf("the nibble moved is %x \n", result);
  return result;
}

uint16_t atoh16(const char* string)
{
  uint16_t result = '\0';
  int index = 0;
  int critical_stop_place = 5;
  if(string[5] == '\0')
  {
    result += hexdigit_converted_16bits(string[2]);
    result <<= 4;
    result += hexdigit_converted_16bits(string[3]);
    result <<= 4;
    result += hexdigit_converted_16bits(string[4]);
  }
  else
  {
    while(index < critical_stop_place)
    {
      result += hexdigit_converted_16bits(string[index]);
      result <<= 4;
      index++;
    }
  }
  if(string[5] != '\0')
  {
    result += hexdigit_converted_16bits(string[5]);
  }
  printf("the nibble moved is %x \n", result);
  return result;
}

uint16_t hexdigit_converted_16bits(char digit)
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

uint8_t hexdigit_converted_8bits(char digit)
{
  if(digit < 'a')
  {
    if(isupper(digit))
    {
      return (uint8_t)(digit - '7');
    }
    return (uint8_t)(digit -'0');
  }
  return (uint8_t)(digit - 'a' + 0xA);
}
