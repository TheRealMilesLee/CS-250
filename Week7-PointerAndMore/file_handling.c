#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename)
{
  Contact *contact_database = malloc(sizeof(Contact));
  FILE *input_file = fopen(filename,"r");
  int label = 0;
  char string[MAX_CONTACTS];
  char* token;
  token = strtok(string, "\t");
  while (fgets(string, MAX_CONTACTS, input_file) && token != NULL )
  {
    puts(token);
    token = strtok(NULL, "\t"); 
  }
}
