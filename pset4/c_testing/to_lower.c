#include <ctype.h>
#include <string.h>
#include <stdio.h>


int main(void)
{
  char arr[10];
  char *word = "HELLO";
  for(int i = 0; i < strlen(word);i++)
  {
    arr[i] = tolower(word[i]);
    printf("%c", arr[i]);
  }

  // if(strcmp(arr, "hello1") == 0)
  // {
  //   puts("true");
  // }
  // else
  // {
  //   puts("false");
  // }
}
