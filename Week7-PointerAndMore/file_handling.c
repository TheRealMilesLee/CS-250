#include <stdio.h>
#include "file_handling.h"
#include <string.h>
void file_read_in_display (char *filename)
{
  Contact *contact_database[MAX_CONTACTS];

  FILE *input_file = fopen(filename,"r");
  char *name_token;
  if (input_file == NULL)
  {
    printf("The file does not exist! Make sure you are using the right txt file! ");
  }

}
