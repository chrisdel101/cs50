
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// SUBRACT letters
char d = 'd';
char b =  'b';
int main(void){
  int diff = d - b;
  char ans = diff + 'a' - 1;
  printf("%c\n", ans);
}