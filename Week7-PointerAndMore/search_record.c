/**
 * @file search_record.c
 * @author Hengyi Li
 * @brief This file is to seach the record of the contacts
 * @version 7.2
 * @date 2021-11-22 12:46 PM
 * @copyright Copyright (c) 2021. Hengyi Li All rights reserved.
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "search_record.h"

void search_record(Contact *contact_database[],
                                  char keyword[MAX_NAME_CHARS], size_t file_size)
{
  size_t looptimes = 0;
  size_t loop = 0;
  char temp_name[MAX_NAME_CHARS];
  remove_new_line_char(keyword);

  while (keyword[looptimes] != '\0')
  {
    keyword[looptimes] = (char)tolower(keyword[looptimes]);
    looptimes++;
  }

  while (loop < file_size)
  {
    strncpy(temp_name, contact_database[loop]->name, MAX_NAME_CHARS);
    looptimes = 0;
    while (temp_name[looptimes] != '\0')
    {
      temp_name[looptimes] = (char)tolower(temp_name[looptimes]);
      looptimes++;
    }
    if (strstr(temp_name, keyword))
    {
      printf("%lu : %s\t%s\t%s\n", loop, contact_database[loop]->name,
      contact_database[loop]->phone, contact_database[loop]->email);
    }
    loop++;
  }
}
