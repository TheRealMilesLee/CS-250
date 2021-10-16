#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "atoh.h"

uint8_t atoh8(const char* string)
{
  uint8_t result = '\0';
  unsigned search_indx = 2;
  unsigned size_of_string = 4;
  unsigned bool_flag = 0;
  /* Detect if the user input is begin with 0x, if not, return 0 */
  if(string[first_index] != '0' && string[second_index] != 'x')
  {
    return 0;
  }
  else
  {
    while(search_indx < size_of_string && !bool_flag )
    {
      if ((string[search_indx] >= '0' && string[search_indx] <= '9') ||
      (string[search_indx] >= 'A' && string[search_indx] <= 'F') ||
      (string[search_indx] >= 'a' && string[search_indx] <= 'f'))
      {
        result += hexdigit_converted_8bits(string[search_indx]);
        if (string[search_indx + next_index] != '\0')
        {
          result <<= move_bits;
          result += hexdigit_converted_8bits(string[search_indx + next_index]);
        }  
        search_indx++;
        bool_flag = true;
      }
      else 
      {
        return 0;
      }
    }
  }  
  return result;
}

uint16_t atoh16(const char* string)
{
  uint16_t result = '\0';
  unsigned search_indx = 2;
  unsigned boolean_flag = 0;
  unsigned index = 1;
  if(string[first_index] != 0 && string[second_index] != 'x')
  {
    return 0;
  }
  else
  {
    while (string[search_indx] != '\0' && !boolean_flag )
    {
      if ((string[search_indx] >= '0' && string[search_indx] <= '9') ||
      (string[search_indx] >= 'A'  && 
      string[search_indx] <= 'F') || (string[search_indx] >= 'a' &&
      string[search_indx] <= 'f'))
      {
        if (string[search_indx + next_index] == '\0')
        {
          result += hexdigit_converted_16bits(string[search_indx]);
          boolean_flag = true;
        }
        else if (string[search_indx + next_index] != '\0' && string[second_last_digits] == '\0')
        {
            result += hexdigit_converted_16bits(string[2]);
            result <<= move_bits;
            result += hexdigit_converted_16bits(string[3]);
            search_indx++;
            boolean_flag = true;
        }  
        else if (string[second_last_digits] != '\0' && string[last_digits] == '\0')
        {
            result += hexdigit_converted_16bits(string[search_indx]);
            result <<= move_bits;
            result += hexdigit_converted_16bits(string[search_indx + next_index]);
            result <<= move_bits;
            result += hexdigit_converted_16bits(string[second_last_digits]);
            search_indx++;
            boolean_flag = true;
        }
        else
        {
          while (string[index + next_index] != '\0' )
          {
          result += hexdigit_converted_16bits(string[index]);
          result <<= move_bits;
          index++;
          }
          if (string[last_digits] != '\0')
          {
            result += hexdigit_converted_16bits(string[last_digits]);
          }
          search_indx++;
          boolean_flag = true;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}

uint16_t hexdigit_converted_16bits(char digit)
{
  if (digit < 'a')
  {
    if (isupper(digit))
    {
      return (uint16_t)(digit - '7');
    }
    return (uint16_t)(digit -'0');
  }
  return (uint16_t)(digit - 'a' + 0xA);
}

uint8_t hexdigit_converted_8bits(char digit)
{
  if (digit < 'a')
  {
    if (isupper(digit))
    {
      return (uint8_t)(digit - '7');
    }
    return (uint8_t)(digit -'0');
  }
  return (uint8_t)(digit - 'a' + 0xA);
}
