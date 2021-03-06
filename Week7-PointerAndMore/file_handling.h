/**
 * @file file_handling.h
 * @author Hengyi Li
 * @brief This file is to handle file
 * @version 30.0
 * @date 2021-11-22 12:47 PM.
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */

#include <stdio.h>
#include "structure_contact.h"

/**
 * @brief This function is to read the txt file from the disk into the contact database array.
 * @param filename is the name of the file that needs to read in.
 * @param contact_database is the array that stores the contact.
 */
size_t file_read_in(char *filename, Contact *contact_database[]);

/**
 * @brief This function is to output the file to the disk
 * @param contact_database is the database that output to
 * @param size is the size of the contacts stores
 */
void file_out_put(char *filename, Contact *contact_database[], size_t size);




