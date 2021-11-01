#include <stdio.h>
#include "add_contact.h"

void add_entry(Contact *contact_database[MAX_CONTACTS])
{
  char name[MAX_NAME_CHARS];
  char phone[MAX_PHONE_CHARS];
  char email[MAX_EMAIL_CHARS];
  size_t index = 0;


  printf("Please input name of the person: ");
  fgets(name, MAX_NAME_CHARS , stdin);
  printf("Please input the phone number of the person: ");
  fgets(phone, MAX_PHONE_CHARS, stdin);
  printf("Please input the email address of the person: ");
  fgets(email, MAX_EMAIL_CHARS, stdin);

  remove_new_line_char(name);
  remove_new_line_char(phone);
  
  while(contact_database[index] != NULL)
  {
    if(contact_database[index] == NULL)
    {
      contact_database[index] = malloc(sizeof(Contact));
      strncpy(contact_database[index]->name, name, MAX_NAME_CHARS);
      strncpy(contact_database[index]->phone, phone, MAX_PHONE_CHARS);
      strncpy(contact_database[index]->email, email, MAX_EMAIL_CHARS);
      contact_database[index+1] = NULL;
    }
    else
    {
      index++;
    } 
  }
  index = 0;
  while (contact_database[index] != NULL)
  {
    printf( "%lu : %s %s %s \n" , index, contact_database[index]->name, 
                  contact_database[index]->phone, contact_database[index]->email);
    index++;
  }
}

void remove_new_line_char (char *origianal_string)
{
  unsigned new_line = (unsigned)strlen(origianal_string) - 1;
  if (origianal_string[new_line] == '\n')
  {
    origianal_string[new_line] = '\0';
  }
}
