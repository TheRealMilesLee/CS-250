#include <stdio.h>
#include "count_total.h"
void display(Contact *contact_database[MAX_CONTACTS], unsigned file_size)
{
  size_t loop;
  for (loop = 0; loop < file_size; loop++)
  {
    printf( "%lu : %s %s %s \n" , loop, (contact_database[loop])->name, 
              (contact_database[loop])->phone, (contact_database[loop])->email);
  }
}
