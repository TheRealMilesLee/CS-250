#include <stdio.h>
#include <string.h>

int main(void)
{
  /* NOTE the following string has embedded TAB characters */
  char string[] = "Test\tthese\ttabs\t\t";
  char* token;

  puts(string);
  token = strtok(string, "\t");
  while (token != NULL)
  {
    puts(token);
    token = strtok(NULL, "\t");
  }

  return 0;
}
