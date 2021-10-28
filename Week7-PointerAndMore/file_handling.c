#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename)
{
  Contact *my_contact[MAX_CONTACTS];
  FILE *input_file = fopen(filename,"r");
  char contact_database[MAX_CONTACTS];
  size_t size_of_file = 0;
  size_t looptimes;
  char* token;
  while ((fgets(contact_database, MAX_CONTACTS, input_file) != NULL))
  {
    size_of_file++;
  }
  for (looptimes = 0; looptimes < size_of_file; looptimes++)
  {
    my_contact[looptimes] = malloc(sizeof(Contact));
  }
  /*
  token = strtok(contact_database, "\n");
  while (token != NULL)
  {
    puts(token);
    token = strtok(NULL, "\n");
  }
  */
}
