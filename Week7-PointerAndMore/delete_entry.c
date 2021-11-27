/**
 * @file delete_entry.c
 * @author Hengyi Li
 * @brief This file is to delete the entry
 * @version 7.1
 * @date 2021-11-22 12:50 PM.
 * @copyright Copyright (c) 2021. Hengyi Li. All right reserved.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "delete_entry.h"

void delete_entry(Contact *contact_database[], size_t file_size, char id[])
{
  size_t user_delete_choice = (size_t)atoi(id);
  size_t looptimes;
  /* cover delete location with next contact position */
  /* And everything moves one level up */
  for (looptimes = user_delete_choice; looptimes < file_size - 1; looptimes++)
  {
    contact_database[looptimes] = contact_database[looptimes + 1];
  }
  free(contact_database[file_size - 1]);
}
