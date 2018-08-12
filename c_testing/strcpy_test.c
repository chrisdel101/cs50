#include <cs50.h>
#include <stdio.h>
#include <string.h>


// #include "../pset5/speller/dictionaries/small"

int main(void)
{
  typedef struct node
  {
    char *word;
    struct node* next;
  }
  node;

  node *mem;
  // blank string store
  char line[126];
  // head of list
  node *head = NULL;
  // node ** memPtr = mem;


  FILE *inptr = fopen("../pset5/speller/dictionaries/small", "r");

  // scan file from inptr to line
  while(fscanf(inptr,"%s",line) != EOF)
  {
    // malloc mem
    mem = malloc(sizeof(node));
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

  // for (node *ptr = memPtr; ptr != NULL; ptr = ptr->next)
  //   // {
  //   //     printf("%s\n", ptr->word);
  //   // }
}