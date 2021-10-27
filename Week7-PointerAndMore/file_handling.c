#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

int get_size_of_file(char *filename)
{
  int file_size = 40;

  return file_size;
}
void file_read_in_display (char *filename)
{
  Contact *contact_database = malloc(sizeof(Contact));
  FILE *input_file = fopen(filename,"r");
  char *token;
  int size_of_file = get_size_of_file(filename);
  char *string = malloc(sizeof(char) * size_of_file);
  fgets(string, size_of_file, input_file);
  token = strtok(string, "\t");
  while (token != NULL)
  {
    strcpy(contact_database->name,token);
    token = strtok(NULL, "\t");
  }


  
}
