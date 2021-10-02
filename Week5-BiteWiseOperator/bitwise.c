/*
 * Your name here
 * A program that implements functions to:
 * 1. reverse the bits of a value
 * 2. convert ascii 0xnn hex representation into an 8-bit value
 */

/*
*
* The assignment is to implement the two functions so that the main program works correctly. 
* Do not modify the main function in any way. Locate your function implementations after 
* main, and use doxygen format to document your functions.
* The purpose of revbits() is to accept an unsigned 8-bit value as a parameter and return the 
* value that results when the bits of the parameter are mirror-image reversed left-to right. So, if 
* the parameter’s bits are 1010 1100 then the return value should be 0011 0101. In hexadecimal, 
* 0xac would be converted into 0x35.
* 
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function is to reverse the bits of a value
 * @param value is the value that needs to be reversed
 * @return the value that results when the bits of the parameter are mirror-image reversed left-
 * to right.
 */
uint8_t revbits(uint8_t value);

/**
 * @brief This function is to convert the ascii character to hexadecimal number
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
  int reversedValue = ~value;
  printf( "This is reversed value: %d" , reversedValue);
  return reversedValue;
}

// TODO: This just have ASCII to integer, needs to be changed into ASCII to hexdecimal.  
uint8_t atoh(const char* string)
{
  size_t index = 0;
  uint8_t intNumberConverted = 0;
  int sign = 1;
  
  /* Skip leading whitespace */
  while (isspace(string[index]))
  {
    index++;
  }

  /* Is leading character a negative? */
  if (string[index] == '-')
  {
    sign = -1;
    index++;
  }
  while(isdigit (string[index]))
  {
    intNumberConverted = 10 * intNumberConverted + (string[index] - '0');
    index++;
  }

  return sign * intNumberConverted;
}
