#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 10

/**
 * determine whether a string contains a character, each
 * case insensitive
 * @param str the string
 * @param ch the character
 * @return 1 if ch is in str; 0 otherwise
 */
unsigned strcontainsi(const char *s, char c);

int main(void)
{
  char string[MAX_CHARS + 1];
  char character;

  printf("Please enter a string: ");
  fgets(string, MAX_CHARS, stdin);
  string[strcspn(string, "\n")] = '\0';

  printf("Please enter a character: ");
  character = (char)getchar();

  if (strcontainsi(string, character))
  {
    printf("%s", string);
    printf(" contains ");
    printf("%c", character);
    printf("\n");
  }
  else
  {
    printf("%s", string);
    printf(" does not contain ");
    printf("%c", character);
    printf("\n");
  }
  return 0;
}

unsigned strcontainsi(const char *str, char ch)
{
  unsigned done = 0;
  unsigned found = 0;
  size_t i = 0;

  while (!done)
  {
    if (str[i] == '\0')
    {
      done = 1;
    }
    else if (toupper(str[i]) == toupper(ch))
    {
      found = 1;
      done = 1;
    }
    else
    {
      i++;
    }
  }
  return found;
}