#include  <stdio.h>
#include <cs50.h>

typedef struct node
{
  int number;
  struct node *next;
}
node;

int main(void)
{
  // pointer set to null
  node *numbers = NULL;

  while(true)
  {
    int number = get_int("number: ");

    if(number == INT_MAX)
    {
      break;
    }
  // MAKE LIST
    bool found = false;
    for(node *ptr = numbers; ptr != NULL; ptr = ptr->next)
    {
      if(ptr->number == number){
        found = true;
        break;
      }
    }
      if(!found)
      {
        node *n = malloc(sizeof(node));
        if(!n)
        {
          return 1;
        }

        n->number = number;
        n->next = NULL;
        if(numbers)
        {
          for(node *ptr = numbers; ptr != NULL;ptr = ptr -> next)
          {
            if(ptr->next == NULL){
              ptr->next = n;
              break;
            }
          }
        }
      }
  }
  node *ptr = numbers;
  while(ptr != NULL)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }
}
