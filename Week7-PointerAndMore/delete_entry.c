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

void delete_entry(Contact *contact_database[MAX_CONTACTS], unsigned delete_id)
{
  unsigned index = 0;
  int deleted = FALSE;
  unsigned loop = 0;
  size_t array_size = 0;
  size_t looptimes;

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

  while (contact_database[loop] != NULL)
  {
    loop++;
    array_size++;
  }
  printf("This is the entry befor the delete: \n");

for (looptimes = 0; looptimes < array_size; looptimes++)
{
  printf( "%u : %s %s %s \n" , looptimes, (contact_database[looptimes])->name, 
                    (contact_database[looptimes])->phone, (contact_database[looptimes])->email);
}
  while ( !deleted)
  {
    if (index == delete_id)
    {
      strncpy((contact_database[index])->name,
                    (contact_database[index + 1])->name , MAX_NAME_CHARS);
      strncpy((contact_database[index])->phone,
                    (contact_database[index + 1])->phone , MAX_PHONE_CHARS);
      strncpy((contact_database[index])->email,
                    (contact_database[index + 1])->email , MAX_EMAIL_CHARS);
      contact_database[3] = NULL;
      deleted =TRUE;
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
