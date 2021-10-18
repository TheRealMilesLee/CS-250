/**
 * @file atoh.c
 * @author Hengyi Li 
 * @brief This file is to convert the ASCII character into the hexadecimal 
 * numbers
 * @version 0.1
 * @date 2021-10-15 11:22 PM
 * @copyright Copyright (c) 2021 Hengyi Li, All rights reserved
 */

#include <stdint.h>
#include <ctype.h>
#include "atoh.h"

uint8_t atoh8(const char *string)
{
  uint8_t result = '\0';
  unsigned search_index = 2;
  unsigned size_of_string = 4;
  unsigned bool_flag = 0;
  unsigned index = 2;
  while (string[index] != '\0')
  {
    index++;
  }
  /* Detect if the user input is begin with 0x, if not, return 0 */
  if (string[FIRST_INDEX] != '0' && string[SECOND_INDEX] != 'x')
  {
    return 0;
  }
  else if(index > 4)
  {
    return 0;
  }
  else
  {
    /* Loop through the string to find if there has invalid digits */
    while (search_index < size_of_string && !bool_flag)
    {
      /* If there does not have invalid digits, continue processing */
      if ((string[search_index] >= '0' && string[search_index] <= '9') ||
          (string[search_index] >= 'A' && string[search_index] <= 'F') ||
          (string[search_index] >= 'a' && string[search_index] <= 'f'))
      {
        /* Convert the ASCII to hexadecimal */
        result += hexdigit_convert_8bits(string[search_index]);
        /* If the input has 2 digits, move 4 digits for spaces and
         * converted the second digits and put it into place */
        if (string[search_index + NEXT_INDEX] != '\0')
        {
          result <<= MOVE_BITS;
          result += hexdigit_convert_8bits(
            string[search_index + NEXT_INDEX]);
        }
        /* See if next digits is valid */
        search_index++;
        /* Done the operation, return the result */
        bool_flag = TRUE;
      }
      else
      {
        /* If the digits is invalid, return the 0 */
        return 0;
      }
    }
  }
  return result;
}

uint16_t atoh16(const char *string)
{
  uint16_t result = '\0';
  unsigned search_index = 2;
  unsigned boolean_flag = 0;
  unsigned index = 1;
  unsigned detection_index = 2;
  while (string[detection_index] != '\0')
  {
    detection_index++;
  }
  /* Detect if the user input is begin with 0x, if not, return 0 */
  if (string[FIRST_INDEX] != 0 && string[SECOND_INDEX] != 'x')
  {
    return 0;
  }
  else if(detection_index > 5)
  {
    return 0;
  }
  else
  {
    /* Loop through the string to find if there has invalid digits */
    while (string[search_index] != '\0' && !boolean_flag)
    {
      /* If there does not have invalid digits, continue processing*/
      if ((string[search_index] >= '0' && string[search_index] <= '9') ||
          (string[search_index] >= 'A' && string[search_index] <= 'F') ||
          (string[search_index] >= 'a' && string[search_index] <= 'f'))
      {
        /* If it only has one digit, i.e. 0xa situation */
        if (string[search_index + NEXT_INDEX] == '\0')
        {
          /* Convert the value and put it into place */
          result += hexdigit_converted_16bits(string[search_index]);
          /* Done the processing, return the value */
          boolean_flag = TRUE;
        }
          /* If it has two digits, i.e. 0xaa situation */
        else if (string[search_index + NEXT_INDEX] != '\0' &&
                 string[SECOND_LAST_DIGITS] == '\0')
        {
          result += hexdigit_converted_16bits(string[search_index]);
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(
            string[search_index + NEXT_INDEX]);
          search_index++;
          boolean_flag = TRUE;
        }
          /* If it has three digits, i.e. 0xaaa situation */
        else if (string[SECOND_LAST_DIGITS] != '\0' &&
                 string[LAST_DIGITS] == '\0')
        {
          result += hexdigit_converted_16bits(string[search_index]);
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(
            string[search_index + NEXT_INDEX]);
          result <<= MOVE_BITS;
          result += hexdigit_converted_16bits(
            string[SECOND_LAST_DIGITS]);
          search_index++;
          boolean_flag = TRUE;
        }
          /* If it has four digits, i.e. 0xaaaa situation */
        else
        {
          while (string[index + NEXT_INDEX] != '\0')
          {
            result += hexdigit_converted_16bits(string[index]);
            result <<= MOVE_BITS;
            index++;
          }
          if (string[LAST_DIGITS] != '\0')
          {
            result += hexdigit_converted_16bits(string[LAST_DIGITS]);
          }
          search_index++;
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
