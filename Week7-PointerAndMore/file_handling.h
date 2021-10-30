/**
 * @file file_handling.h
 * @author Hengyi Li
 * @brief This file is to handling the file read in and get the size of the file
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021. Hengyi Li, All rights reserved
 */

#include <stdio.h>
#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
#define MAX_CONTACTS 1024

/**
 * @brief This structure is used to storing the contact information
 */
typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

/**
 * @brief This function is to read the txt file from the disk into the contact database array. 
 * @param filename is the name of the file that needs to read in.
 * @param contact_database is the array that stores the contact.
 */
void file_read_in(char *filename, Contact *contact_database[MAX_CONTACTS]);



