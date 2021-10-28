#include <stdio.h>
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
 * @brief This function is to read the txt file from the disk into the contact database array. 
 * @param filename is the name of the file that needs to read in.
 * @param contact_database is the array that stores the contact.
 */
void file_read_in(char *filename, char contact_database[MAX_CONTACTS]);
/**
 * @brief This function is to display the current entry for the database 
 * @param contact_database is the array that stores the contact
 * @param array_size is the size of the array that use to display the array content
 */
void display_entry(char contact_database[MAX_CONTACTS], size_t array_size);

