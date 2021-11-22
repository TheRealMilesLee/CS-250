/**
 * @file add_contact.c
 * @author Hengyi Li
 * @brief This file is to add contact
 * @version 9.0
 * @date 2021-11-22 12:30 PM
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#include <stdio.h>
#include "add_contact.h"

void add_entry(Contact *contact_database[], size_t file_size)
{
  char name[MAX_NAME_CHARS];
  char phone[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];
  size_t loop;

  printf("Please input name of the person: ");
  fgets(name, MAX_NAME_CHARS, stdin);
  printf("Please input the phone number of the person: ");
  fgets(phone, MAX_PHONE_CHARS, stdin);
  printf("Please input the email address of the person: ");
  fgets(email, MAX_EMAIL_CHARS, stdin);

  /* Get rid of the new line character */
  remove_new_line_char(name);
  remove_new_line_char(phone);
  remove_new_line_char(email);

  contact_database[file_size - 1] = malloc(sizeof(Contact) * file_size);
  strncpy(contact_database[file_size - 1]->name, name, MAX_NAME_CHARS);
  strncpy(contact_database[file_size - 1]->phone, phone, MAX_PHONE_CHARS);
  strncpy(contact_database[file_size - 1]->email, email, MAX_EMAIL_CHARS);

  for (loop = 0; loop < file_size; loop++)
  {
    printf("%lu : %s %s %s \n", loop, contact_database[loop]->name,
           contact_database[loop]->phone, contact_database[loop]->email);
  }
}
