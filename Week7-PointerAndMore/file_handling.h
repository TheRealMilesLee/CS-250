/**
 * @file file_handling.h
 * @author Hengyi Li
 * @brief This file is to handling the file read in and get the size of the file
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021. Hengyi Li, All rights reserved
 */

#include <stdio.h>
#include "structure_contact.h"

/**
 * @brief This function is to read the txt file from the disk into the contact database array. 
 * @param filename is the name of the file that needs to read in.
 * @param contact_database is the array that stores the contact.
 */
size_t file_read_in(char *filename, Contact *contact_database[MAX_CONTACTS]);

/**
 * @brief This function is to output the final decision of the contact file
 * @param contact_database is the database that stores the contacts
 */
void file_out_put(Contact *contact_database[MAX_CONTACTS], unsigned file_size);




