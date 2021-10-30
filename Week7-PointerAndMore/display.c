#include "display.h"
void display_entry(char contact_database[MAX_CONTACTS], size_t array_size)
{
  size_t looptimes;
  for (looptimes = 0; looptimes < array_size; looptimes++)
  {
    printf("%d : %s \n",looptimes, contact_database[looptimes]);
  }
}
