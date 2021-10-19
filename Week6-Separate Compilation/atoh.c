/**
 * @file atoh.c
 * @author Hengyi Li 
 * @brief This file is to convert the ASCII character into the hexadecimal 
 * numbers
 * @version 0.1
 * @date 2021-10-18 8:54 PM
 * @copyright Copyright (c) 2021 Hengyi Li, All rights reserved
 */

#include <stdint.h>
#include <ctype.h>
#include "atoh.h"

uint8_t atoh8(const char *string)
{
  uint8_t result = '\0';
  unsigned search_index = 2;
  
  /* Detect if the user input is begin with 0x, if not, return 0 */
  if (string[FIRST_INDEX] != '0' && string[SECOND_INDEX] != 'x')
  {
    return 0;
  }
  else
  {
    if (!isdigit(string[THIRD_INDEX]) && !isalpha(string[THIRD_INDEX]))
    {
      return 0;
    }
    else
    {
      /* Loop through the string to find if there has invalid digits */
      while (string[search_index] != '\0')
      {
        /* If there does not have invalid digits, continue processing */
        if ((string[search_index] < '0' || string[search_index] > '9') &&
            (string[search_index] < 'A' || string[search_index] > 'F') &&
            (string[search_index] < 'a' || string[search_index] > 'f'))
        {
          return 0;
        }
        else
        {
          search_index++;
        }
      }
      /* Convert the ASCII to hexadecimal */
      result += hexdigit_convert_8bits(string[FIRST_DIGIT]);
      /* If the input has 2 digits, move 4 digits for spaces and
       * converted the second digits and put it into place */
      if (string[SECOND_DIGIT] != '\0')
      {
        result <<= MOVE_BITS;
        result += hexdigit_convert_8bits(string[SECOND_DIGIT]);
      }
    }
  }
  return result;
}

uint16_t atoh16(const char *string)
{
  uint16_t result = '\0';
  unsigned search_index = 2;
  unsigned item_index = 2;
  /* Detect if the user input is begin with 0x, if not, return 0 */
  if (string[FIRST_INDEX] != 0 && string[SECOND_INDEX] != 'x')
  {
    return 0;
  }
  else
  {
    /* Determine the situation of only has 0x */
    if (!isdigit(string[THIRD_INDEX]) && !isalpha(string[THIRD_INDEX]))
    {
      return 0;
    }
    else
    {
      /* Loop through the string to find if there has invalid digits */
      while (string[search_index] != '\0')
      {
        /* If there does not have invalid digits, continue processing*/
        if ((string[search_index] < '0' || string[search_index] > '9') &&
            (string[search_index] < 'A' || string[search_index] > 'F') &&
            (string[search_index] < 'a' || string[search_index] > 'f'))
        {
          return 0;
        }
        else
        {
          search_index++;
        }
      }
      /* If it only has one digit, i.e. 0xa situation */
      if (string[SECOND_DIGIT] == '\0')
      {
        /* Convert the value and put it into place */
        result += hexdigit_converted_16bits(string[FIRST_DIGIT]);
      }
        /* If it has two digits, i.e. 0xaa situation */
      else if (string[SECOND_DIGIT] != '\0' && string[THIRD_DIGIT] == '\0')
      {
        result += hexdigit_converted_16bits(string[FIRST_DIGIT]);
        result <<= MOVE_BITS;
        result += hexdigit_converted_16bits(string[SECOND_DIGIT]);
      }
        /* If it has three digits, i.e. 0xaaa situation */
      else if (string[THIRD_DIGIT] != '\0' && string[LAST_DIGITS] == '\0')
      {
        result += hexdigit_converted_16bits(string[FIRST_DIGIT]);
        result <<= MOVE_BITS;
        result += hexdigit_converted_16bits(string[SECOND_DIGIT]);
        result <<= MOVE_BITS;
        result += hexdigit_converted_16bits(string[THIRD_DIGIT]);
      }
        /* If it has four digits, i.e. 0xaaaa situation */
      else
      {
        if (string[FIRST_DIGIT] == '0')
        {
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(string[SECOND_DIGIT]);
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(string[THIRD_DIGIT]);
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(string[LAST_DIGITS]);
        }
        else
        {
          while (string[item_index + NEXT_INDEX] != '\0' &&
                 item_index < LAST_DIGITS)
          {
            result += hexdigit_converted_16bits(string[item_index]);
            result <<= MOVE_BITS;
            item_index++;
          }
          if (string[LAST_DIGITS] != '\0')
          {
            result += hexdigit_converted_16bits(string[LAST_DIGITS]);
          }
        }
      }
    }
  }
  return result;
}

uint16_t hexdigit_converted_16bits(char digit)
{
  if (digit < 'a')
  {
    /* Situation of upper case letters */
    if (isupper(digit))
    {
      return (uint16_t)(digit - '7');
    }
    return (uint16_t)(digit - '0');
  }
  return (uint16_t)(digit - 'a' + 0xA);
}

uint8_t hexdigit_convert_8bits(char digit)
{
  if (digit < 'a')
  {
    /* Situation of upper case letters */
    if (isupper(digit))
    {
      return (uint8_t)(digit - '7');
    }
    return (uint8_t)(digit - '0');
  }
  return (uint8_t)(digit - 'a' + 0xA);
}
