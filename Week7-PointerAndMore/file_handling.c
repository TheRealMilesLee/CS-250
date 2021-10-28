#include <string.h>
#include <stdlib.h>
#include "file_handling.h"

void file_read_in_display (char *filename, char contact_database[MAX_CONTACTS])
{
  Contact *my_contact;
  FILE *input_file = fopen(filename,"r");
  size_t size_of_file = 0;
  size_t looptimes = 0;
  fgets(contact_database, MAX_CONTACTS, input_file);
}

void display_entry(char contact_database[MAX_CONTACTS], size_t array_size)
{
  size_t looptimes;
  for (looptimes = 0; looptimes < array_size; looptimes++)
  {
    printf("%d : %s \n",looptimes, contact_database[looptimes]);
  }
}
