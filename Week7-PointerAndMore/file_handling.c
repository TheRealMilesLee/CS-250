#include <stdio.h>
#include "file_handling.h"
#include <string.h>
#include <stdlib.h>

void file_read_in_display (char *filename)
{
  Contact *contact_database = malloc(sizeof(Contact));
  FILE *input_file = fopen(filename,"r");

}
