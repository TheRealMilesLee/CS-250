#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename)
{
  Contact *contact_database = malloc(sizeof(Contact));
  FILE *input_file = fopen(filename,"r");
  char *database; 
  int file_size = 0;
  int looptimes_database = 0;
  size_t looptimes;
  char* token;
  while (fgets(database, MAX_CONTACTS, input_file))
  {
    file_size++;
  }
  database = malloc(sizeof(char) * file_size);
  token = strtok(database, "\t");
  while (token != NULL)
  {
    *contact_database[looptimes].name = puts(token);
    token = strtok(NULL, "\t");
  }

  for ( looptimes = 0; looptimes < file_size; looptimes++)
  {
    *contact_database[looptimes].name = database[looptimes_database];
    *contact_database[looptimes].phone = database[looptimes_database + 1];
    *contact_database[looptimes].email = database[looptimes_database + 2];
    looptimes_database + 3;
  }

  printf("%s", *contact_database[0].name);
}
