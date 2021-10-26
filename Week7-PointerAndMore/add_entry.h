#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;