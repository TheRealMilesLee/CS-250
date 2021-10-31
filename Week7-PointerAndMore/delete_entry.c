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
  int index = 0;
  int loop = 0;
  size_t array_size = 0;
  size_t looptimes;
  int done = FALSE;
  contact_database[0] = malloc(sizeof(Contact));
  contact_database[1] = malloc(sizeof(Contact));
  contact_database[2] = malloc(sizeof(Contact));

  strncpy((contact_database[0])->name, "Sabine", MAX_NAME_CHARS);
  strncpy((contact_database[0])->phone, "111-222-33", MAX_PHONE_CHARS);
  strncpy((contact_database[0])->email, "new_contact.email", MAX_EMAIL_CHARS);

  strncpy((contact_database[1])->name, "tobedeleted", MAX_NAME_CHARS);
  strncpy((contact_database[1])->phone, "111222333", MAX_PHONE_CHARS);
  strncpy((contact_database[1])->email, "tobedeleted@email", MAX_EMAIL_CHARS);

  strncpy((contact_database[2])->name, "Misaka", MAX_NAME_CHARS);
  strncpy((contact_database[2])->phone, "660-542-11", MAX_PHONE_CHARS);
  strncpy((contact_database[2])->email, "misaka@email.com", MAX_EMAIL_CHARS);
  
  printf("This is the entry befor the delete: \n");
  while (contact_database[loop] != NULL)
  {
    printf( "%d : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    array_size++;
    loop++;
  }
  
  while ( contact_database[index] != NULL)
  {
    if(index == delete_id)
    {
      for (looptimes = delete_id; looptimes < array_size; looptimes++)
      {
        contact_database[looptimes] = contact_database[looptimes+1];
      }
      done = TRUE;
    }
    index++;
  }
  
  printf("This is the entry after the delete: \n");
  loop = 0;
  while (contact_database[loop] != NULL)
  {
    printf( "%u : %s %s %s \n" , loop, (contact_database[loop])->name, 
                    (contact_database[loop])->phone, (contact_database[loop])->email);
    loop++;
  }
}
