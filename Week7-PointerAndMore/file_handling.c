#include <stdio.h>
#include "file_handling.h"

void file_read_in_display (char filename)
{
  Contact *contact_database;
  FILE *input_file;
  char *name_token;
  if ((input_file = fopen(filename,"r"))== NULL)
  {
    printf("The file does not exist! Make sure you are using the right txt file! ");
    exit(1);
  }
  name_token = contact_database->name;
}
