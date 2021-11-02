#include <stdio.h>
#include "add_contact.h"

void add_entry(Contact *contact_database[MAX_CONTACTS], unsigned file_size)
{
  char name[MAX_NAME_CHARS];
  char phone[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];
  size_t index;
  unsigned termination = 0;

  printf("Please input name of the person: ");
  fgets(name, MAX_NAME_CHARS , stdin);
  printf("Please input the phone number of the person: ");
  fgets(phone, MAX_PHONE_CHARS, stdin);
  printf("Please input the email address of the person: ");
  fgets(email, MAX_EMAIL_CHARS, stdin);

  remove_new_line_char(name);
  remove_new_line_char(phone);
  remove_new_line_char(email);
  
  for (index = 0; index < file_size - 1; index++)
  {
    if(contact_database[index] == NULL)
    {
      contact_database[index] = malloc(sizeof(Contact));
      strncpy(contact_database[index]->name, name, MAX_NAME_CHARS);
      strncpy(contact_database[index]->phone, phone, MAX_PHONE_CHARS);
      strncpy(contact_database[index]->email, email, MAX_EMAIL_CHARS);
      termination = 1;
    }
  }
}
 
