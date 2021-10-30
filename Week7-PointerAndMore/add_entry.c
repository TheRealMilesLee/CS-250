#include <stdio.h>
#include "add_entry.h"

void add_entry(Contact *contact_database[MAX_CONTACTS])
{
  Contact new_contact;
  char name[MAX_NAME_CHARS];
  char phone[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];

  printf("Please input name of the person: ");
  fgets(name, MAX_NAME_CHARS, stdin);
  printf("Please input the phone number of the person: ");
  fgets(phone, MAX_PHONE_CHARS, stdin);
  printf("Please input the email address of the person: ");
  fgets(email, MAX_EMAIL_CHARS, stdin);

  strncpy(new_contact.name, name, MAX_NAME_CHARS);
  strncpy(new_contact.phone, phone, MAX_PHONE_CHARS);
  strncpy(new_contact.email, email, MAX_EMAIL_CHARS);

  
}
