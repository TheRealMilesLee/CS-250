

#ifndef WEEK7_POINTERANDMORE_ADD_CONTACT_H
#define WEEK7_POINTERANDMORE_ADD_CONTACT_H
#include <string.h>
#include <stdlib.h>
#include "structure_contact.h"

/**
 * @brief This function is to add a entry in the end of the contact database
 * @param contact_database is the database that stores the contact
 */
void add_entry(Contact *contact_database[MAX_CONTACTS]);

/**
 * @brief This function is to remove the new line character after ther user input
 * @param origianal_string is the string that we modified
 */
void remove_new_line_char (char *origianal_string);
#endif
