/**
 * @file structure_contact.c
 * @author Hengyi Li
 * @brief This file is the structure file for the entire program
 * @version 0.1
 * @date 2021-11-01
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved
 * 
 */
#include "structure_contact.h"

void remove_new_line_char (char *origianal_string)
{
  unsigned new_line = (unsigned)strlen(origianal_string) - 1;
  if (origianal_string[new_line] == '\n')
  {
    origianal_string[new_line] = '\0';
  }
}
