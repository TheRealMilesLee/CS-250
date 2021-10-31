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
  Contact *contact_database[MAX_CONTACTS];
  char user_input;
  char search_keyword[MAX_NAME_CHARS];
  int done = FALSE;
  
  if (argc != 2)
  {
    fprintf(stderr, "usage: input your filename as the user database%s \n", argv[0]);
    return 1;
  }

  delete_entry(contact_database, 2);
  /*file_read_in(argv[1], contact_database);*/
  /*
  while (!done)
  {
    display_entry(contact_database, 4);
    printf("S: Search \n A: Add \n D: Delete \n Q: Quit \n Choice: ");
    fgets(user_input, sizeof(char), user_input);
    if (user_input == "s" || user_input == "S")
    {
      printf("Please input the word that you looking for: ");
      fgets(search_keyword, MAX_NAME_CHARS, stdin);
      search_record(contact_database, search_keyword);
    }
    else if (user_input == "a" || user_input == "A")
    {
      add_entry(contact_database);
    }
    else if (user_input == "d" || "D")
    {
      
    }
    else
    {
      done = TRUE;
    }
  }

  */
  return 0;
}
