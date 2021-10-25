#include <stdio.h>
#include <string.h>

//特殊测试例子，记得问
int main(void)
{
  /* NOTE the following string has embedded TAB characters */
  char string[] = "I\tjust\twant\tto\ttry\twhether\tthis\tis\tworking\tunder\tthe\tspaces\tinstead\tof\tthe\ttabs\t\t";
  char* token;

  puts(string);
  token = strtok(string, "\t");
  while (token != NULL)
  {
    puts(token);
    token = strtok(NULL, "\t");
  }
  puts(string);
  return 0;
}
