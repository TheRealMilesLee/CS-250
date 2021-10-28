#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "add_entry.h"

void add_entry(Contact *contact_database[MAX_CONTACTS])
{
  Contact *contact = malloc(sizeof(Contact));
  size_t loop = 0; 
  int found_empty = 0;
  char phone_number[MAX_NAME_CHARS];
  char name[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];
  printf("Please input the name: "); 
  gets(name);
  strncpy(contact->name, name, strlen(name));
  printf("Please input the phone number: ");
  gets(phone_number);
  strncpy(contact->phone, phone_number, strlen(phone_number));
  printf("Please input the email address: ");
  gets(email);
  strncpy(contact->email, email, strlen(email));

  while(!found_empty)
  {
    if(contact_database[loop] == NULL)
    {
      contact_database[loop] = contact;
      found_empty = 1;
    }
  }
  
}
