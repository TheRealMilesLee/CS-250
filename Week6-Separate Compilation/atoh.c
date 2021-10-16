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
  if (string[FIRST_INDEX] != '0' && string[SECOND_INDEX] != 'x')
  {
    return 0;
  }
  else
  {
    while (search_indx < size_of_string && !bool_flag )
    {
      if ((string[search_indx] >= '0' && string[search_indx] <= '9') ||
      (string[search_indx] >= 'A' && string[search_indx] <= 'F') ||
      (string[search_indx] >= 'a' && string[search_indx] <= 'f'))
      {
        result += hexdigit_convert_8bits(string[search_indx]);
        if (string[search_indx + NEXT_INDEX] != '\0')
        {
          result <<= MOVE_BITS;
          result += hexdigit_convert_8bits(string[search_indx + NEXT_INDEX]);
        }  
        search_indx++;
        bool_flag = TRUE;
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
  if (string[FIRST_INDEX] != 0 && string[SECOND_INDEX] != 'x')
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
        if (string[search_indx + NEXT_INDEX] == '\0')
        {
          result += hexdigit_converted_16bits(string[search_indx]);
          boolean_flag = TRUE;
        }
        else if (string[search_indx + NEXT_INDEX] != '\0' && 
        string[SECOND_LAST_DIGITS] == '\0')
        {
            result += hexdigit_converted_16bits(string[search_indx]);
            result <<= MOVE_BITS;
            result += hexdigit_converted_16bits(string[search_indx +NEXT_INDEX]);
            search_indx++;
            boolean_flag = TRUE;
        }  
        else if (string[SECOND_LAST_DIGITS] != '\0' && 
        string[LAST_DIGITS] == '\0')
        {
            result += hexdigit_converted_16bits(string[search_indx]);
            result <<= MOVE_BITS;
            result += hexdigit_converted_16bits(string[search_indx + NEXT_INDEX]);
            result <<= MOVE_BITS;
            result += hexdigit_converted_16bits(string[SECOND_LAST_DIGITS]);
            search_indx++;
            boolean_flag = TRUE;
        }
        else
        {
          while (string[index + NEXT_INDEX] != '\0' )
          {
          result += hexdigit_converted_16bits(string[index]);
          result <<= MOVE_BITS;
          index++;
          }
          if (string[LAST_DIGITS] != '\0')
          {
            result += hexdigit_converted_16bits(string[LAST_DIGITS]);
          }
          search_indx++;
          boolean_flag = TRUE;
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

uint8_t hexdigit_convert_8bits(char digit)
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
