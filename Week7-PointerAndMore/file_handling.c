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

  if (input_file == NULL)
  { 
    fprintf(stderr, "The file is not valid, please make sure if its exists or not empty");
    exit(1);
  }
  else
  {
    while (fgets(temp_array, MAX_LINE_LENGTH, input_file))
    {
      printf("%u : %s", size_of_file++, temp_array); 
    }
    for (looptimes = 0; looptimes < size_of_file; looptimes++)
    {
      contact_database[looptimes] = malloc(sizeof(Contact));
    }
    
    token = strtok(temp_array, "\t");
    for (looptimes = 0; looptimes < size_of_file; looptimes++)
    {
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
    printf("This is the contact after reading in the files \n");
    while (contact_database[loop] != NULL)
    {
      printf( "%lu : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
      loop++;
    }
  }
  fclose(input_file);
}

void file_out_put(Contact *contact_database[MAX_CONTACTS])
{
  size_t loop = 0;
  FILE *output_file = fopen("2.txt", "w");
  while (contact_database[loop] != NULL)
  {
    fprintf (output_file, "%s \t %s \t %s \n", (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    loop++;
  }
  fclose(output_file);
}
