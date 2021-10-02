/**
 * @file atod.c
 * @author Jon Beck
 * @brief illustrate functions based on K&R page 71
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021 All rights reserved
 * 
 */

#include <ctype.h>
#include <stdio.h>
#define MAXLINE 80

/**
 * @brief This function is to convert ASCII character to floating point numbers.
 * @param string is the ASCII character that needs to be convert.
 * @return double is the number has been converted.
 */
double atod(const char* string);

int main(void)
{
  char line[MAXLINE];
  double sum = 0.0;

  printf("Entering a floating point value: ");
  while (fgets(line, MAXLINE, stdin))
  {
    printf("running sum: %g\nEnter another value (ctrl-d to stop): ", sum += atod(line));
  }
  printf("\n");
  return 0;
}

double atod(const char* string)
{
  double value = 0.0;
  double fractional_power = 1.0;
  size_t index = 0;
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
  while (isdigit (string[index]))
  {
    value = 10.0 * value + (string[index] - '0');
    index++;
  }

  if(string[index] == '.')
  {
    index++;
  }

  /* Digits after the decimal point */
  while(isdigit(string[index]))
  {
    value = 10.0 * value + (string[index] - '0');
    index++;
    fractional_power *= 10.0;
  } 
  return sign * value / fractional_power;
}
