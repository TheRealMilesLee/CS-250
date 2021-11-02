#include <stdio.h>
#include "count_total.h"
void display(Contact *contact_database[MAX_CONTACTS])
{
  size_t loop = 0;
  unsigned size_of_file = calculate_number_of_contacts(contact_database);
  while (loop < size_of_file)
    {
      printf( "%lu : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
      loop++;
    }
}
