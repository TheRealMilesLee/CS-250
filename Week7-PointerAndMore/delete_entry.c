/**
 * @file delete_entry.c
 * @author Hengyi Li
 * @brief This file is to delete the entry that user named
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021. Hengyi Li, All rights reserved.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "delete_entry.h"

void delete_entry(Contact *contact_database[MAX_CONTACTS], int delete_id)
{
  size_t user_delete_choice = (size_t) delete_id;
  int index = 0;
  int loop = 0;
  size_t array_size = 0;
  size_t looptimes;
  int done = FALSE;

  while (contact_database[loop] != NULL)
  {
    array_size++;
    loop++;
  }
  
  while ( contact_database[index] != NULL)
  {
    if(index == delete_id)
    {
      for (looptimes = user_delete_choice; looptimes < array_size; looptimes++)
      {
        contact_database[looptimes] = contact_database[looptimes + 1];
      }
      done = TRUE;
    }
    index++;
  }
  
  loop = 0;
  while (contact_database[loop] != NULL)
  {
    printf( "%u : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    loop++;
  }
}
