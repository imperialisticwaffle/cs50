// Implements a dictionary's functionality

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 186019;       // You’ll likely want to increase the number of buckets, as by changing N, to something larger! Used prime number for decreased collisions; 1.3x max words.

// Hash table
node *table[N];

// Number of loaded nodes/words
unsigned int num_loaded = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    /* TODO
        Hash word to obtain value
        Access linked list at that index
        Traverse linked list comparing cases using strcasecmp */
    unsigned int index = hash(word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)       // For loop to traverse linked list in event of collisions AND single elements in bucket
    {
        if (strcasecmp(tmp->word, word) == 0)
            return true;
        else
            continue;
    }
    return false;
}

// Hashes word to a number. Takes word as input and outputs corresponding number to which bucket to store word in
// DJB2A hash function adapted from https://gist.github.com/yorickdewid/dc600cb52a4ab90747d2 (http://www.cse.yorku.ca/%7Eoz/hash.html)
unsigned int hash(const char *word)
{
    /* TODO:
        Needs to take input (word possibly with apostrophes)
        Needs to output numerical index b/w 0 and N - 1 inclusive
        Deterministic (gives same output every time for same input)
        If the function provides a number greater than N, you can take value % N */
    unsigned int hash = 5381, ui_hash = 0;
    int c;
    while ((c = *word++))
        hash = hash * 33 ^ tolower(c);      // Case insensitive
    ui_hash = hash % N;
    return ui_hash;
}

// Loads dictionary into memory, returning true if successful, else false. Open and read dictionary file to load data into hash table. False if not enough mem to load/couldn't open file.
bool load(const char *dictionary)
{
    /* TODO:
        Open dictionary
        Read strings from file one at a time
        Create new node for each word
        Hash word to obtain a value
        Insert node into hash table at that location */
    FILE *inptr = fopen(dictionary, "r");
    char str[46];

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open dictionary\n");
        return false;
    }

    while (fscanf(inptr, "%s", str) > 0)    // While reading from dictionary works and is not EOF
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fprintf(stderr, "Could not allocate memory for new node\n");
            return false;
        }
        strcpy(n->word, str);       // Transfer from temp string to new node

        unsigned int index = hash(n->word);
        if (table[index] == NULL)       // If nothing at our table index (no linked list so far)
        {
            table[index] = n;       // This node n is the new head of linked list at the index in our HT array
            n->next = NULL;        // Update its pointers to NULL
            num_loaded++;
        }
        else
        {
            n->next = table[index];     // First point to old head of list
            table[index] = n;           // Make n become new head
            num_loaded++;
        }
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return num_loaded;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < 186019; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;     // Set temporary pointer to current cursor
            cursor = cursor->next;  // Shift cursor to next item in LL
            free(tmp);              // Free temporary pointer
        }
    }
    return true;
}
