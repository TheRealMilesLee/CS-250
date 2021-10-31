#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
main (void)
{
  Contact *contacts[1024];
  Contact new_contact;
  unsigned i = 0;
  unsigned bool = 0;
  /* NOTE the following string has embedded TAB characters */
  char string[] =
    "Harry Potter\t423-749-6268\tboy_who_lived@hp.com\nHermione Granger\t243-961-7287\tbest_girl@hp.com\nRon Weasley\t756-816-0257\tbest_bud@hp.com\n";
  char *token;
  char *add_name;
  char *add_phone;
  char *add_email;
  puts (string);

  new_contact = malloc (sizeof (Contact));
  token = strtok (string, "\t");
  puts (token);
  add_name = token;
  strncpy (new_contact->name, add_name, MAX_NAME_CHARS);

  do
  {
    token = strtok (NULL, "\t");
    puts (token);
    add_phone = token;
    strncpy (new_contact->phone, add_phone, MAX_PHONE_CHARS);

    token = strtok (NULL, "\n");
    puts (token);
    add_email = token;
    strncpy (new_contact->email, add_email, MAX_EMAIL_CHARS);

    contacts[i] = new_contact;

    new_contact = malloc (sizeof (Contact));

    if (i < 1024)
    {
      i++;
      token = strtok (NULL, "\t");

      if (token != NULL)
        {
          puts (token);
          add_name = token;
          strncpy (new_contact->name, add_name, MAX_NAME_CHARS);
        } 
      else
      {
          bool = 1;
      }
     }
    }
  while (token != NULL && bool == 0);

  for (size_t index = 0; index < i; index++)
    {
      unsigned num = (unsigned) index;
      fprintf (stdout, "%u: %s  %s %s\n", num, contacts[num]->name,
           contacts[num]->phone, contacts[num]->email);
    }
  return 0;
}