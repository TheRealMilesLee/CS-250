/**
 * @file search_record.c
 * @author Hengyi Li
 * @brief This file is used to search a existing record in the current student database
 * @version 0.1
 * @date 2021-10-30 4:30PM.
 * @copyright Copyright (c) 2021. Hengyi Li, All rights reserved.
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "search_record.h"

void search_record(Contact *contact_database[MAX_CONTACTS], 
                                  char keyword[MAX_NAME_CHARS], unsigned file_size)
{
  size_t index;
  size_t position;
  remove_new_line_char(keyword);
  index = 0;


  position = 0;
  while (contact_database[index]->name[position] != '\0')
  {
    if(isupper(contact_database[index]->name[position]))
    {
      tolower (contact_database[index]->name[position]);
        while (keyword[index] != '\0')
        {
          if (keyword[index] == contact_database[index]->name[position])
          {
            printf("%lu : %s %s %s \n",index,(contact_database[index])->name, 
            (contact_database[index])->phone, (contact_database[index])->email);
          }
          index++;
        }
        position++;
    }
  }
}

