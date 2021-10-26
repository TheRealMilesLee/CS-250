/**
 * @file main.c
 * @author Hengyi Li
 * @brief This file is the main program of the student database
 * @version 0.1
 * @date 2021-10-24
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include "file_handling.h"
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "usage: input your filename as the user database%s \n", argv[0]);
    return 1;
  }

  file_read_in_display(argv[1]);
  return 0;
}
