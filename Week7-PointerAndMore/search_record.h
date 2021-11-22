/**
 * @file search_record.h
 * @author Hengyi Li
 * @brief This file is used to search  the record using the keyword
 * @version 0.1
 * @date 2021-10-30
 * @copyright Copyright (c) 2021 Hengyi Li. All rights reserved
 *
 */
#include "structure_contact.h"


/**
 * @brief This file is to search the record
 * @param contact_database is the database search to
 * @param keyword is the keyword that the user looking to
 * @param file_size is the size of total contact
 */
void search_record(Contact *contact_database[],
                                  char keyword[MAX_NAME_CHARS],
                                  unsigned file_size);
