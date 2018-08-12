#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//add length so it works
#define LENGTH 45
#define HASHTABLE_SIZE 65536
// include other functions getting used
int hashValue(const char *word);
bool load();
void check();

https://cs50.stackexchange.com/questions/27133/pset5-speller-load-function-not-working-properly

typedef struct node
  {
    char word[LENGTH + 1];
    struct node *next;
  }
  node;
node *hash_table[HASHTABLE_SIZE] = {NULL};

int main(void){
  load();
  check();

}
void check()
{
  for(int i = 0;i < 10; i++)
  {
  printf("%p", hash_table[i]);

  }
}

bool load()
{
  puts("running load...");
FILE *inptr = fopen("./dictionaries/small", "r");

  char temp[LENGTH+1];

  // load dictionary to test


   while(fscanf(inptr,"%s",temp) != EOF)
  {
    // malloc mem
    node *mem = malloc(sizeof(node));
      if(mem == NULL)
      {
        return 1;
      }

      // copy line into node's word
        strcpy(mem->word, temp);
    // hash it
        int hash_index = hashValue(temp);
        // if null, head is empty
        if(hash_table[hash_index] == NULL)
        {
            // insert at head of linked list
          // same as head = mem
          hash_table[hash_index] = mem;
          // make next null
          mem->next = NULL;

        }
        else
        {
          // set next to current head
           mem->next = hash_table[hash_index];
        // reassign head to new node
          hash_table[hash_index] = mem;
        }

      }
      fclose(inptr);
      puts("made it to end");
      return true;

}


// int main(void)
// {


// }




int hashValue(const char *word)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    // returns a number
    return hash % sizeof(HASHTABLE_SIZE);
}