#include <stdio.h>
#include "add_contact.h"

void add_entry(Contact *contact_database[MAX_CONTACTS])
{
  char name[MAX_NAME_CHARS];
  char phone[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];
  size_t index = 0;
  int done = 0;

  printf("Please input name of the person: ");
  fgets(name, MAX_NAME_CHARS + 2, stdin);
  printf("Please input the phone number of the person: ");
  fgets(phone, MAX_PHONE_CHARS + 2, stdin);
  printf("Please input the email address of the person: ");
  fgets(email, MAX_EMAIL_CHARS + 2, stdin);
  
  while(!done)
  {
    if(contact_database[index] == NULL)
    {
      contact_database[index] = malloc(sizeof(Contact));
      strncpy((contact_database[index])->name, name, MAX_NAME_CHARS);
      strncpy((contact_database[index])->phone, phone, MAX_PHONE_CHARS);
      strncpy((contact_database[index])->email, email, MAX_EMAIL_CHARS);
      done = 1;
    }
    else
    {
      index++;
    } 
  }
}
