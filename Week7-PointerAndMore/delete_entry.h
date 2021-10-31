#include "structure_contact.h"
#define TRUE 1
#define FALSE 0


/**
 * @brief This function is to delete the entry by using the id as parameter to delete the   
 * correspond record.
 * @param contact_database is the entire database that used to operate
 * @param delete_id is the id that user wants to delete
 */
void delete_entry(Contact *contact_database[MAX_CONTACTS], int delete_id);
