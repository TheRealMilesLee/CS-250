#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename, Contact *contact_database[MAX_CONTACTS])
{
  FILE *input_file = fopen(filename,"r");
  Contact *contact_array;
  size_t size_of_file = 0;
  size_t looptimes;
  while (fgets(contact_database, MAX_CONTACTS, input_file))
  {
    size_of_file++;
  }
  contact_array[size_of_file];
  for (looptimes = 0; looptimes < size_of_file; looptimes++)
  {
      contact_array[looptimes] = malloc(sizeof(Contact));
  }

  
}
