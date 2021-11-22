/**
 * @file add_contact.h
 * @author Hengyi Li
 * @brief This file is the header of the add contact file
 * @version 9.9
 * @date 2021-11-02 3:38. A.M.
 * @copyright Copyright (c) 2021. Hengyi Li. All rights reserved.
 */


#ifndef ADD_CONTACT_H
#define ADD_CONTACT_H
#include <stdlib.h>
#include "structure_contact.h"

/**
 * @brief This function is to add the entry
 * @param contact_database is the database to add
 * @param file_size is the size of the contacts file
 */
void add_entry(Contact *contact_database[], size_t file_size);

#endif
