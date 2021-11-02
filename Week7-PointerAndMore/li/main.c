/**
 * @file main.c
 * @author Hengyi Li
 * @brief This is a contact management program
 * @version 7.8
 * @date 2021-11-02 3:08AM
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#include <stdio.h>
#include "main.h"
int main(int argc, char *argv[])
{
  Contact *contact_database[MAX_CONTACTS];
  char user_input[3];
  char delete_id[3];
  char search_keyword[MAX_NAME_CHARS];
  int done = FALSE;
  unsigned file_size = 0;
  if (argc != 2)
  {
    fprintf(stderr, "usage: input your filename as the user database%s \n", argv[0]);
    return 1;
  }

  file_size = (unsigned)file_read_in(argv[1], contact_database);
  while (!done)
  {
    printf("\n");
    printf("S: Search \n");
    printf("A: Add \n");
    printf("D: Delete \n");
    printf("Q: Quit \n");
    printf("Choice: ");
    fgets(user_input, 3, stdin);
    printf("\n");
    if (user_input[0] == 's' || user_input[0] == 'S')
    {
      printf("Please input the word that you looking for: ");
      fgets(search_keyword, MAX_NAME_CHARS, stdin);
      search_record(contact_database, search_keyword, file_size);
    }
    else if (user_input[0] == 'a' || user_input[0] == 'A')
    {
      file_size = file_size + 1;
      add_entry(contact_database, file_size);
    }
    else if (user_input[0] == 'd' || user_input[0] == 'D')
    {
      printf("Please input the id that you want to deleted: ");
      fgets(delete_id, 3, stdin);
      delete_entry(contact_database, delete_id, file_size);
      file_size = file_size - 1;
    }
    else
    {
      file_out_put(contact_database, file_size);
      done = TRUE;
    }
  }
  return 0;
}
