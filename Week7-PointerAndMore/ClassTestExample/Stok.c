#include <stdio.h>
#include <string.h>
typedef struct
{
  char name[41];
  char phone[13];
  char email[31];
} Contact;

int main(void)
{
  Contact myContact;
  /* NOTE the following string has embedded TAB characters */
  char string[] = "Test\tthese\ttabs\t\t";
  char* token;
  token = strtok(string, "\t");
  while (token != NULL)
  {
    strncpy(myContact.name, token, 41);
    token = strtok(NULL, "\t");
    strncpy(myContact.phone, token, 13);
    token = strtok(NULL, "\t");
  }
  printf("%s : %s", myContact.name ,myContact.phone);

  return 0;
}
