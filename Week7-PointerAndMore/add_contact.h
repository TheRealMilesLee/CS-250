

#ifndef WEEK7_POINTERANDMORE_ADD_CONTACT_H
#define WEEK7_POINTERANDMORE_ADD_CONTACT_H
#include <stdlib.h>
#include "structure_contact.h"
#include "count_total.h"

/**
 * @brief This function is to add a entry in the end of the contact database
 * @param contact_database is the database that stores the contact
 */
void add_entry(Contact *contact_database[MAX_CONTACTS], unsigned file_size);


#endif
