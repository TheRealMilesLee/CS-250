#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename, char contact_database[MAX_CONTACTS])
{
  Contact *my_contact;
  FILE *input_file = fopen(filename,"r");
  size_t size_of_file = 0;
  size_t looptimes = 0;
  while (fgets(contact_database, MAX_CONTACTS, input_file) && !feof(input_file))
  {
    if(strstr(contact_database, "\t"))
    {
      *my_contact = *contact_database;
    }
  }
}
