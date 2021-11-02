/**
 * @file search_record.c
 * @author Hengyi Li
 * @brief This file is to seach the record of the contacts
 * @version 7.1
 * @date 2021-11-02 3:03 AM
 * @copyright Copyright (c) 2021. Hengyi Li All rights reserved.
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "search_record.h"

void search_record(Contact *contact_database[MAX_CONTACTS], 
                                  char keyword[MAX_NAME_CHARS], unsigned file_size)
{
  size_t looptimes = 0;
  size_t loop = 0;
  size_t index = 0;
  remove_new_line_char(keyword);
  while (keyword[index] != '\0')
  {
    if (isupper(keyword[index]))
    {
      for (looptimes = 0; looptimes < file_size; looptimes++)
      {
        if (strstr(contact_database[looptimes]->name, keyword))
        {
          printf("%lu : %s %s %s \n", looptimes, contact_database[looptimes]->name, 
          contact_database[looptimes]->phone, contact_database[looptimes]->email);
        }
      }
      keyword[index] = (char)tolower(keyword[index]);
    }
    else
    {
      while (loop < file_size)
      {
        if (strstr(contact_database[loop]->name, keyword))
        {
          printf("%lu : %s%s%s \n", loop, contact_database[loop]->name, 
          contact_database[loop]->phone, contact_database[loop]->email);
        }
        loop++;
      }
      index++;
    }
  }
}
