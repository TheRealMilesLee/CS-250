/**
 * @file file_handling.c
 * @author Hengyi Li
 * @brief This file is to handling the file
 * @version 0.2
 * @date 2021-11-22 12:48 PM.
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include "file_handling.h"

size_t file_read_in(char *filename, Contact *contact_database[])
{
  char temp_array[MAX_CONTACTS];
  FILE *input_file = fopen(filename, "r");
  size_t looptimes;
  char *token;
  unsigned file_size;
  size_t loop;

  if (input_file == NULL)
  {
    fprintf(stderr, "The file is not valid");
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
      token = strtok(NULL, "\t");
      strncpy(contact_database[looptimes]->phone, token, MAX_PHONE_CHARS);
      token = strtok(NULL, "\n");
      strncpy(contact_database[looptimes]->email, token, MAX_EMAIL_CHARS);
      looptimes++;
    }
    file_size = (unsigned)looptimes;
    for (loop = 0; loop < file_size; loop++)
    {
      printf("%lu : %s %s %s \n", loop, contact_database[loop]->name,
             contact_database[loop]->phone, contact_database[loop]->email);
    }
  }

  fclose(input_file);
  return looptimes;
}

void file_out_put(char *filename, Contact *contact_database[], size_t size)
{
  size_t loop = 0;
  FILE *output_file = fopen(filename, "w");
  while (loop < size)
  {
    fprintf(output_file, "%s\t%s\t%s\n",
              (contact_database[loop])->name,
              (contact_database[loop])->phone,
              (contact_database[loop])->email);
    loop++;
  }
  fclose(output_file);
}
