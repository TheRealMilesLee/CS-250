/**
 * @file search_record.h
 * @author your name (you@domain.com)
 * @brief This file is used to search  the record using the keyword
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved
 * 
 */

#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
#define MAX_CONTACTS 1024

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

/**
 * @brief This function is to search the record using the keyword that user provided
 * @param contact_database is the database that search for
 * @param keyword is the keyword that the user looking to
 */
void search_record(Contact *contact_database[MAX_CONTACTS], 
                                  char keyword[MAX_NAME_CHARS]);
