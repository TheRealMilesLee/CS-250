#include <stdio.h>
#include "structure_contact.h"

/**
 * @brief this function is to print out the database
 * @param contact_database is the database that stores the contacts
 * @param file_size is the size of the database
 */
void print_out_database(Contact *contact_database[], size_t file_size);

/**
 * @brief This function is to free memory after finished using database
 * @param contact_database is the database that stores the contacts
 * @param file_size is the size of the database
 */
void free_memory(Contact *contact_database[], size_t file_size);
