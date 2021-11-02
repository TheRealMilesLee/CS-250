#include "structure_contact.h"

void remove_new_line_char (char *origianal_string)
{
  unsigned new_line = (unsigned)strlen(origianal_string) - 1;
  if (origianal_string[new_line] == '\n')
  {
    origianal_string[new_line] = '\0';
  }
}
