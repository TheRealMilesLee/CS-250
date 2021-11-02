

#ifndef ADD_CONTACT_H
#define ADD_CONTACT_H
#include <stdlib.h>
#include "structure_contact.h"

/**
 * @brief This function is to add the entry
 * @param contact_database is the database to add
 * @param file_size is the size of the contacts file
 */
void add_entry(Contact *contact_database[MAX_CONTACTS], unsigned file_size);

#endif
