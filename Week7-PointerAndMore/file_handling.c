#include <string.h>
#include <stdlib.h>
#include "file_handling.h"
#include "display.h"

void file_read_in (char *filename, Contact *contact_database[MAX_CONTACTS])
{
  Contact my_contact;
  char temp_array[MAX_CONTACTS];
  FILE *input_file = fopen(filename,"r");
  unsigned size_of_file = 0;
  size_t looptimes;
  char *token;

  if (input_file == NULL)
  { 
    fprintf(stderr, "The file is not valid, please make sure if its exists or not empty");
    exit(1);
  }
  else
  {
    while (fgets(temp_array, MAX_CONTACTS, input_file))
    {
      printf("%u : %s", size_of_file++, temp_array); 
    }
    for (looptimes = 0; looptimes < size_of_file; looptimes++)
    {
      contact_database = malloc(sizeof(Contact) * looptimes);
    }
    token = strtok(temp_array, "\t");
    for (looptimes = 0; looptimes < size_of_file; looptimes+3)
    {
      my_contact.name = temp_array[0];
      my_contact.phone = temp_array[1];
      my_contact.email = temp_array[2];
    }
      puts(token);
      token = strtok(NULL, "\t");
    }
  }
}
