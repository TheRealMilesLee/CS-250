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
 * @brief This function is to search the existing record by the name keywords
 * @param contact_database is the database that used to search for
 */
void search_record(Contact *contact_database[MAX_CONTACTS]);