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

void delete_entry(Contact *contact_database[],
                              char delete_id[LENGTH_OF_CHARS])
{
  size_t user_delete_choice = (size_t)atoi(delete_id);
  size_t index = 0;
  unsigned loop = 0;
  size_t array_size = 0;
  size_t looptimes;
  unsigned done = FALSE;
  while (contact_database[loop] != NULL)
  {
    array_size++;
    loop++;
  }
  while (contact_database[index] != NULL)
  {
    if (index == user_delete_choice)
    {
      for (looptimes = index; looptimes < array_size; looptimes++)
      {
        contact_database[looptimes] = contact_database[looptimes + 1];
      }
      done = TRUE;
    }
    index++;
  }
}
