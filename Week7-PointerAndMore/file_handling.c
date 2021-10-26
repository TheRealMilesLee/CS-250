#include <stdio.h>
#include "file_handling.h"
#include <string.h>

int get_file_size(char *filename)
{
  FILE *file_to_be_counted = fopen(filename, "r");
  char *count_ptr;
  int file_size = 0;

  count_ptr = strtok(file_to_be_counted, "\t");
  while (count_ptr != NULL)
  {
    file_size++;
    count_ptr = strtok(NULL, "\t");
  }
  return file_size;
}
void file_read_in_display (char *filename)
{
  Contact *contact_database_name[MAX_NAME_CHARS];

  FILE *input_file = fopen(filename,"r");
  char *name_token;
  if (input_file == NULL)
  {
    printf("The file does not exist! Make sure you are using the right txt file! ");
  }

}
