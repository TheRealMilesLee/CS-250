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
#include "delete_entry.h"

void delete_entry(Contact *contact_database[MAX_CONTACTS],int delete_id)
{
  unsigned index = 0;
  int deleted = 0;
  while (contact_database[index] != NULL && !deleted)
  {
    if (index == delete_id)
    {
      strncpy((contact_database[index])->name,
                    (contact_database[index + 1])->name , MAX_NAME_CHARS);
      strncpy((contact_database[index])->phone,
                    (contact_database[index + 1])->phone , MAX_PHONE_CHARS);
      strncpy((contact_database[index])->email,
                    (contact_database[index + 1])->email , MAX_EMAIL_CHARS);
      deleted = 1;
    }
    index++;
  }
}
