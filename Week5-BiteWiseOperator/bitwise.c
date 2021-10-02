/*
 * Your name here
 * A program that implements functions to:
 * 1. reverse the bits of a value
 * 2. convert ascii 0xnn hex representation into an 8-bit value
 */

/*
*
* The purpose of revbits() is to accept an unsigned 8-bit value as a parameter and return the 
* value that results when the bits of the parameter are mirror-image reversed left-to right. So, if 
* the parameter’s bits are 1010 1100 then the return value should be 0011 0101. In hexadecimal, 
* 0xac would be converted into 0x35.
* 
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
  
/*  uint8_t value;*/
  uint8_t value_reversed;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s 0xnn\n", argv[0]);
    fprintf(stderr, "  where 0xnn is an 8-bit hex value\n");
    return 1;
  }
  

  /*value = (uint8_t)(atoh(argv[1]));
  printf("0x%x reversed\n", value);*/
  value_reversed = revbits(5);
  printf("reversed is 0x%x\n", value_reversed);
  return 0;
}

uint8_t revbits(uint8_t value)
{ 
  unsigned char totalBits = sizeof(value) * 8;
  unsigned int reverseNumber = 0;
  unsigned int index = 0;
  unsigned int temp = 0;

  while(index < totalBits)
  {
    if(value & (1 << index))
    {
      reverseNumber = 1 << ((totalBits -1) - index);
    }
  }
  return reverseNumber;
}

/* TODO: This just ASCII characters, needs to be changed into hexdecimal.  */
uint8_t atoh(const char* string)
{
  char value = '\0';
  uint8_t typecastingValue = '\0';
  size_t index = 0;
  while (string[index] == '0' || string[index] =='x' )
  {
    index++;
  }
  while(string[index] != '\0')
  {
      if((string[index]>= 'a') && (string[index] <= 'z'))
      {
        value = string[index] - 'a' +0x61;
        typecastingValue = typecastingValue + (uint8_t) value;
      }
      index++;
  }
  
  return typecastingValue;
}
