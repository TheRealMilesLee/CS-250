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
                              char delete_id[LENGTH_OF_CHARS],
                              size_t file_size)
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
  file_size = file_size - 1;
  for (loop = 0; loop < file_size; loop++)
  {
    printf("%d : %s %s %s \n", loop, contact_database[loop]->name,
           contact_database[loop]->phone, contact_database[loop]->email);
  }
}
