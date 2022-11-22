/**
 * @file main.c
 * @author Hengyi Li
 * @brief This is a contact management program
 * @version 7.9
 * @date 2021-11-22 12:47 PM
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#include <stdio.h>
#include "main.h"
#include "file_handling.h"
#include "add_contact.h"
#include "delete_entry.h"
#include "search_record.h"
#include "structure_contact.h"
#define FALSE 0
#define TRUE 1
#define MAX_SINGLE_CHAR_INPUT_SIZE 3
#define USER_INPUT_CHAR_POSITION 0
int main(int argc, char *argv[])
{
  Contact *contact_database[MAX_CONTACTS];
  char user_input[MAX_SINGLE_CHAR_INPUT_SIZE];
  char delete_id[MAX_SINGLE_CHAR_INPUT_SIZE];
  char search_keyword[MAX_NAME_CHARS];
  unsigned done = FALSE;
  size_t file_size = 0;
  if (argc != 2)
  {
    fprintf(stderr, "usage: input your filename as the user database%s \n", argv[0]);
    return 1;
  }
  /* File read in */
  file_size = (unsigned)file_read_in(argv[1], contact_database);
  while (!done)
  {
    printf("\n");
    printf("S: Search \n");
    printf("A: Add \n");
    printf("D: Delete \n");
    printf("Q: Quit \n");
    printf("Choice: ");
    fgets(user_input, MAX_SINGLE_CHAR_INPUT_SIZE, stdin);
    printf("\n");
    /* Search */
    if (user_input[USER_INPUT_CHAR_POSITION] == 's' ||
    user_input[USER_INPUT_CHAR_POSITION] == 'S')
    {
      printf("Please input the word that you looking for: ");
      fgets(search_keyword, MAX_NAME_CHARS, stdin);
      search_record(contact_database, search_keyword, file_size);
    }
    /* Add */
    else if (user_input[USER_INPUT_CHAR_POSITION] == 'a' ||
    user_input[USER_INPUT_CHAR_POSITION] == 'A')
    {
      file_size = file_size + 1;
      add_entry(contact_database, file_size);
      print_out_database(contact_database, file_size);
    }
    /* Delete */
    else if (user_input[USER_INPUT_CHAR_POSITION] == 'd' ||
    user_input[USER_INPUT_CHAR_POSITION] == 'D')
    {
      printf("Please input the id that you want to deleted: ");
      fgets(delete_id, MAX_SINGLE_CHAR_INPUT_SIZE, stdin);
      delete_entry(contact_database, file_size, delete_id);
      file_size = file_size - 1;
      print_out_database(contact_database, file_size);
    }
    /* Exit */
    else
    {
      file_out_put(argv[1], contact_database, file_size);
      free_memory(contact_database, file_size);
      done = TRUE;
    }
  }
  return 0;
}

void print_out_database(Contact *contact_database[], size_t file_size)
{
  size_t looptimes;
  for (looptimes = 0; looptimes < file_size; looptimes++)
  {
    printf("%lu : %s %s %s \n", looptimes, contact_database[looptimes]->name,
        contact_database[looptimes]->phone, contact_database[looptimes]->email);
  }
}

void free_memory(Contact *contact_database[], size_t file_size)
{
  size_t looptimes;
  for (looptimes = 0; looptimes < file_size; looptimes++)
  {
    free(contact_database[looptimes]);
  }
}
