#include <string.h>
#include <stdlib.h>
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
 * @brief This function is to add a entry in the end of the contact database
 * @param contact_database is the database that stores the contact
 */
void add_entry(Contact *contact_database[MAX_CONTACTS]);
