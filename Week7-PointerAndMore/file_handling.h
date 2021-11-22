/**
 * @file file_handling.h
 * @author Hengyi Li
 * @brief This file is to handle file
 * @version 29.9
 * @date 2021-11-02 3:12 AM.
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
 * @param file_size is the size of the contacts stores
 */
void file_out_put(char *filename, Contact *contact_database[], size_t file_size);




