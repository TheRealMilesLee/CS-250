/**
 * @file delete_entry.h
 * @author Hengyi Li
 * @brief This file is to delete the entry
 * @version 6.6
 * @date 2021-11-22 12:50 PM
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#include "structure_contact.h"
#define TRUE 1
#define FALSE 0
# define LENGTH_OF_CHARS 2

/**
 * @brief This function is to delete the entry
 * @param contact_database is the database to delete
 * @param delete_id is the id that comes from user input
 */
void delete_entry(Contact *contact_database[],
                              char delete_id[LENGTH_OF_CHARS]);
