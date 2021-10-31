/**
 * @file search_record.h
 * @author your name (you@domain.com)
 * @brief This file is used to search  the record using the keyword
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved
 * 
 */
#include "structure_contact.h"


/**
 * @brief This function is to search the record using the keyword that user provided
 * @param contact_database is the database that search for
 * @param keyword is the keyword that the user looking to
 */
void search_record(Contact *contact_database[MAX_CONTACTS], 
                                  char *keyword[MAX_NAME_CHARS]);
