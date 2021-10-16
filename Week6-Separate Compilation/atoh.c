
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "atoh.h"

uint8_t atoh8(const char* string)
{
  uint8_t result = '\0';
  int search_indx = 2;
  while(string[search_indx] != '\0' )
  {
    if((string[search_indx] >= '0' && string[search_indx] <= '9') || (string[search_indx] >= 'A'  && 
    string[search_indx] <= 'F') || (string[search_indx] >= 'a' && string[search_indx] <= 'f'))
    {
          result += hexdigit_converted_8bits(string[2]);
          if(string[3] != '\0')
          {
            result <<= 4;
            result += hexdigit_converted_8bits(string[3]);
          }  
          search_indx++;
    }
    else 
    {
      return 0;
    }
    }
  printf("the nibble moved is %x \n", result);
  return result;
}

uint16_t atoh16(const char* string)
{
  uint16_t result = '\0';
  int search_indx = 2;
  int index = 1;
  while(string[search_indx] != '\0' )
  {
    if((string[search_indx] >= '0' && string[search_indx] <= '9') || (string[search_indx] >= 'A'  && 
    string[search_indx] <= 'F') || (string[search_indx] >= 'a' && string[search_indx] <= 'f'))
    {
      if(string[3] == '\0')
      {
        result += hexdigit_converted_16bits(string[2]);
      }
      else if(string[3] != '\0' && string[4] == '\0')
      {
          result += hexdigit_converted_16bits(string[2]);
          result <<= 4;
          result += hexdigit_converted_16bits(string[3]);
      }  
      else if(string[4] != '\0' && string[5] == '\0')
      {
          result += hexdigit_converted_16bits(string[2]);
          result <<= 4;
          result += hexdigit_converted_16bits(string[3]);
          result <<= 4;
          result += hexdigit_converted_16bits(string[4]);
      }
      else
      {
        while(string[index + 1] != '\0' )
        {
        result += hexdigit_converted_16bits(string[index]);
        result <<= 4;
        printf("The content of the place is  %c \n", string[index]);
        index++;
        }
        if(string[5] != '\0')
        {
          result += hexdigit_converted_16bits(string[5]);
        }
      }
      search_indx++;
    }
    else
    {
      return 0;
    }
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
  return (uint16_t)(digit - 'a' + 0xA);
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
