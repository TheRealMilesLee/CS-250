/**
 * @file delete_entry.h
 * @author Hengyi Li
 * @brief This file is to delete the entry
 * @version 6.5
 * @date 2021-11-02 3:39 A.M
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */
#include "structure_contact.h"
#define TRUE 1
#define FALSE 0

/**
 * @brief This function is to delete the entry
 * @param contact_database is the database to delete
 * @param delete_id is the id that comes from user input
 * @param file_size is the size of the contact files
 */
void delete_entry(Contact *contact_database[MAX_CONTACTS], char delete_id[2], unsigned file_size);
