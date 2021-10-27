#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename)
{
  Contact *contact_database = malloc(sizeof(Contact));
  FILE *input_file = fopen(filename,"r");
  char string[MAX_NAME_CHARS];
  char* token;
  fgets(string, MAX_CONTACTS, input_file);
  token = strtok(string, "\t");
  while (token != NULL)
  {
    token = strtok(NULL, "\t");
  }
  contact_database->name = strstr(token);
  
}
