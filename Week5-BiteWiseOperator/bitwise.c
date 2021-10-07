/*
 * Hengyi Li
 * A program that implements functions to:
 * 1. reverse the bits of a value
 * 2. convert ascii 0xnn hex representation into an 8-bit value
 */

/**
 * @file bitwise.c
 * @author Hengyi Li
 * @brief A program to reverse the bits of value and convert ascii to hex
 * @version 0.1
 * @date 2021-10-03 12:43AM
 * @copyright Copyright (c) 2021  Hengyi Li All rights reserved
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ARRAY_SIZE 2
#define HEX_CHARACTER_PLACE 2
#define NEXT_HEX_CHARACTER_PLACE 3
#define MOVE_FOUR_BIT_FOR_PLACE 4

/**
 * @brief This function is to reverse the bits of a value
 * @param value is the value that needs to be reversed
 * @return the value that results when the bits of the parameter are 
 * mirror-image reversed left-to right.
 */
uint8_t revbits(uint8_t value);

/**
 * @brief This function is to convert the ascii character to hexadecimal 
 * number
 * @param string Accepts a ascii character that used to be converted
 * @return a hexadecimal number that the ascii character being converted.
 */
uint8_t atoh(const char* string);

int main(int argc, char** argv)
{
  uint8_t value;
  uint8_t value_reversed;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s 0xnn\n", argv[0]);
    fprintf(stderr, "  where 0xnn is an 8-bit hex value\n");
    return 1;
  }

  value = (uint8_t)(atoh(argv[1]));
  value_reversed = revbits(value);

  printf("0x%x reversed is 0x%x\n", value, value_reversed);
  return 0;
}

uint8_t revbits(uint8_t value)
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

uint8_t atoh(const char* string)
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
