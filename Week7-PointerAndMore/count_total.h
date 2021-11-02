#include "structure_contact.h"

/**
 * @brief This function is to output the contact database
 * @param contact_database is the database that used to display
 */
void display(Contact *contact_database[MAX_CONTACTS]);

/**
 * @brief This function is to calculate the number of the contacts
 * @param contact_database  is the database to count
 * @return the size of the array
 */
unsigned calculate_number_of_contacts(Contact *contact_database[MAX_CONTACTS]);
