#include <stdio.h>
#include "revbits.h"

int main(int argc, char** argv)
{
  uint8_t value_8bits;
  uint8_t value_reversed_8bits;
  uint16_t value_16bits;
  uint16_t value_reversed_16bits;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s 0xnn\n", argv[0]);
    fprintf(stderr, "  where 0xnn is an 8-bit hex value\n");
    return 1;
  }

  value_8bits = (uint8_t)(atoh8(argv[1]));
  value_reversed_8bits = revbits8(value_8bits);
  printf("0x%x reversed is 0x%x\n", value_8bits, value_reversed_8bits);

  value_16bits = (uint16_t)(atoh16(argv[1]));
  value_reversed_16bits = revbits16(value_16bits);
  printf("0x%x reversed is 0x%x\n", value_16bits, value_reversed_16bits);
  
  return 0;
}