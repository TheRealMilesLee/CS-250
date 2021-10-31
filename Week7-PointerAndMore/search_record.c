/**
 * @file search_record.c
 * @author Hengyi Li
 * @brief This file is used to search a existing record in the current student database
 * @version 0.1
 * @date 2021-10-30 4:30PM.
 * @copyright Copyright (c) 2021. Hengyi Li, All rights reserved.
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "search_record.h"

void search_record(Contact *contact_database[MAX_CONTACTS], 
                                  char keyword[MAX_NAME_CHARS])
{
  unsigned index = 0;
  while (contact_database[index] != NULL)
  {
    if(strstr((contact_database[index])->name, keyword))
    {
      printf("%u : %s %s %s \n",index,(contact_database[index])->name, 
      (contact_database[index])->phone, (contact_database[index])->email);
      index++;
    }
    else
    {
      index++;
    }
  }
}
