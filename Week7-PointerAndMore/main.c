/**
 * @file main.c
 * @author Hengyi Li
 * @brief This file is the main program of the student database
 * @version 0.1
 * @date 2021-10-24
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include "main.h"
int main(int argc, char *argv[])
{
  char contact_database[MAX_CONTACTS];
  char user_input;
  if (argc != 2)
  {
    fprintf(stderr, "usage: input your filename as the user database%s \n", argv[0]);
    return 1;
  }
  file_read_in(argv[1], contact_database);
  printf("S: Search \n A: Add \n D: Delete \n Q: Quit \n Choice: ");
  gets(user_input);
  
  return 0;
}
