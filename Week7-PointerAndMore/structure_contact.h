#ifndef WEEK7_POINTERANDMORE_STRUCTURE_CONTACT_H
#define WEEK7_POINTERANDMORE_STRUCTURE_CONTACT_H
#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
#define MAX_CONTACTS 1024
#define MAX_LINE_LENGTH 82

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

#endif
