#include <string.h>
#include <stdlib.h>
#include "file_handling.h"

void file_read_in (char *filename, Contact *contact_database[MAX_CONTACTS])
{
  Contact my_contact;
  char temp_array[MAX_CONTACTS];
  FILE *input_file = fopen(filename,"r");
  unsigned size_of_file = 0;
  size_t looptimes;
  char *token;
  size_t loop = 0;
  int index = 0;

  if (input_file == NULL)
  { 
    fprintf(stderr, "The file is not valid, please make sure if its exists or not empty");
    exit(1);
  }
  else
  {
    token = strtok(temp_array, "\t");

    while (fgets(temp_array, MAX_CONTACTS, input_file))
    {
      printf("%u : %s", size_of_file++, temp_array); 
    }
    for (looptimes = 0; looptimes < size_of_file; looptimes++)
    {
      contact_database[looptimes] = malloc(sizeof(Contact));
    }
    for (looptimes = 0; looptimes < size_of_file; looptimes++)
    {
      printf("%s", token);
      strncpy(my_contact.name, token, MAX_NAME_CHARS);
      strncpy((contact_database[looptimes])->name, my_contact.name, MAX_NAME_CHARS);
      token = strtok(NULL, "\t");
      strncpy(my_contact.phone, token, MAX_PHONE_CHARS);
      strncpy((contact_database[looptimes])->phone, my_contact.phone, MAX_PHONE_CHARS);
      token = strtok(NULL, "\t");
      strncpy(my_contact.email, token, MAX_EMAIL_CHARS);
      strncpy((contact_database[looptimes])->email, my_contact.email, MAX_EMAIL_CHARS);
      token = strtok(NULL, "\n");
    }
    printf("\n");
    while (contact_database[loop] != NULL)
  {
    printf( "%u : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    loop++;
  }
  }
}
