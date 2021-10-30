#define MAX_CONTACTS 1024
#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

/**
 * @brief This function is to delete the entry by using the id as parameter to delete the   
 * correspond record.
 * @param contact_database is the entire database that used to operate
 * @param delete_id is the id that user wants to delete
 */
void delete_entry(Contact *contact_database[MAX_CONTACTS], int delete_id);