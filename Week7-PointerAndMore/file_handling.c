#include <string.h>
#include <stdlib.h>
#include "file_handling.h"

void file_read_in (char *filename, Contact *contact_database[MAX_CONTACTS])
{
  char temp_array[MAX_CONTACTS];
  FILE *input_file = fopen(filename,"r");
  size_t looptimes;
  char *token;

  if (input_file == NULL)
  { 
    fprintf(stderr, "The file is not valid, please make sure if its exists or not empty");
    exit(1);
  }
  else
  {
    looptimes = 0;
    while (fgets(temp_array, MAX_LINE_LENGTH, input_file))
    {
      contact_database[looptimes] = malloc(sizeof(Contact));
      token = strtok(temp_array, "\t");
      strncpy(contact_database[looptimes]->name, token, MAX_NAME_CHARS);
      token = strtok(NULL,"\t");
      strncpy(contact_database[looptimes]->phone, token, MAX_PHONE_CHARS);
      token = strtok(NULL,"\n");
      strncpy(contact_database[looptimes]->email, token, MAX_EMAIL_CHARS);
      looptimes++;
    }
    display(contact_database);
  }
  fclose(input_file);
}

void file_out_put(Contact *contact_database[MAX_CONTACTS])
{
  size_t loop = 0;
  unsigned file_size = calculate_number_of_contacts(contact_database);
  FILE *output_file = fopen("2.txt", "w");
  while (loop < file_size)
  {
    fprintf (output_file, "%s \t %s \t %s \n", (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    loop++;
  }
  fclose(output_file);
}
