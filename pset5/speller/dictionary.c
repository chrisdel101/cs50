// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <xlocale.h>

#include "dictionary.h"

// SOURCES CITED AS RESOURCES FOR ASSIGNMENT
//Used this post as reference -  https://cs50.stackexchange.com/questions/27133/pset5-speller-load-function-not-working-properly
//Used this post for my hash function - https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/


// include hash function prototype
int hashValue(const char *word);

// struct for the node type
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// set hash table to const size, at null
node *hash_table[HASHTABLE_SIZE] = {NULL};
// set global tracker for word count
int count = 0;

// SIZE
unsigned int size(void)
{
    // return global count when called
    return count;
}

// CHECK
bool check(const char *word)
{
// MAKE LOWER
    // get word length
    int len = strlen(word);
    // make array to store word
    char arr[len + 1];
    // loop over chars, make lowercase, put into an array
    for (int i = 0; i < strlen(word); i++)
    {
        arr[i] = tolower(word[i]);
    }
    // add end of string marker - not sure why(got this from resources cited)
    arr[len] = '\0';


// HASH VALUE
    //hash to get bucket index - need original/lower word case
    int hash_index = hashValue(arr);
    // set head to first node in bucket/array - node
    node *head = hash_table[hash_index];
    //set cursor to head to start
    node *cursor = head;
    // run until at last cursor becomes null
    while (cursor != NULL)
    {
        //compare loaded in word to word in node, 0 is equal
        if (strcmp(arr, cursor->word) == 0)
        {

            return true;
        }
        // move cursor to where head-> next points
        cursor = head->next;
        // move head ahead also to match cursor
        head = cursor;

    }
    // if word not found break
    return false;
}



// LOAD
bool load(const char *dictionary)
{
    //open file of words
    FILE *inptr = fopen(dictionary, "r");
    // create global function array holder
    char temp[LENGTH + 1];

    // whiile not end of file, use this as per Zymalya video
    while (fscanf(inptr, "%s", temp) != EOF)
    {
        // malloc mem for each node
        node *mem = malloc(sizeof(node));
        // break condition
        if (mem == NULL)
        {
            return 1;
        }
        // copy line from file into node's -> word
        strcpy(mem->word, temp);
        // hash it
        int hash_index = hashValue(temp);
        // if null, head is empty, first node
        if (hash_table[hash_index] == NULL)
        {
            // insert node at head of linked list
            // same as head = mem
            hash_table[hash_index] = mem;
            // make next null since no next yet
            mem->next = NULL;
            // add global count
            count++;
        }
        else
        {
            // not first node - point next to the current head
            mem->next = hash_table[hash_index];
            // reassign head to new node
            hash_table[hash_index] = mem;
            count++;
        }
    }
    fclose(inptr);
    // call size function to return global count
    size();
    return true;
}


// UNLOAD
bool unload(void)
{
    // loop through const size of hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // set cursor to start at first array index
        node *cursor = hash_table[i];
        // while not null, unload
        while (cursor != NULL)
        {
            // set temp to cursor
            node *temp = cursor;
            // point cursor at cursor's own next node
            cursor = cursor-> next;
            // free
            free(temp);
        }
    }
    return true;
}

// HASH FUNCTION - see cited resources
int hashValue(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    // returns a number
    return hash % HASHTABLE_SIZE;
}