/**
 * @file structure_contact.h
 * @author Hengyi Li
 * @brief This is the header file for the structure
 * @version 0.2
 * @date 2021-11-22 12:47 PM
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#ifndef STRUCTURE_CONTACT_H
#define STRUCTURE_CONTACT_H
#include <string.h>
#define MAX_NAME_CHARS 42
#define MAX_PHONE_CHARS 14
#define MAX_EMAIL_CHARS 32
#define MAX_CONTACTS 1024
#define MAX_LINE_LENGTH 88

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

/**
 * @brief This function is to remove the new line character after ther user input
 * @param origianal_string is the string that we modified
 */
void remove_new_line_char (char *origianal_string);

#endif
