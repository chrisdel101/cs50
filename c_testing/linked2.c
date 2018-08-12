#include <cs50.h>
#include <stdio.h>
#include <string.h>


// #include "../pset5/speller/dictionaries/small"

int main(void)
{
  // typedef struct node
  // {
  //   char word[126];
  //   struct node* next;
  // }
  // node;
  typedef struct node
  {
    char word[LENGTH + 1];
    struct node *next;
  }
  node;


  // blank string store
  char line[126];
  // head of list
  node *head;
  // node ** memPtr = mem;


  FILE *inptr = fopen("../pset5/speller/dictionaries/small", "r");

  // scan file from inptr to line
  while(fscanf(inptr,"%s",line) != EOF)
  {
    for(int i = 0;i<100i++){
      printf("%s\n", temp);
    }
    // malloc mem
    node *mem = malloc(sizeof(node));
      if(mem == NULL)
      {
        return 1;
      }
      // first node
      if(head == NULL)
      {
      // copy line into node's word
        strcpy(mem->word, line);
        // make next null
        mem->next = NULL;
        // this node the head
        head = mem;

      } else {
        // if second node +

        // set to line
        strcpy(mem->word, line);
        // set next to previous node's head
        mem->next = head;
        // set head to current new node
        head = mem;

      }

  }

  for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%s\n", ptr->word);
    }
}