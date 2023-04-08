// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2048;

// ChatGPT suggested hash size, used it for testing and seeing how fast my implementation can go
// Looking back, way too big for normal operations
// const unsigned int N = 183119;

// Hash table
node *table[N] = { NULL };

void free_linked_list(node *n);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_index = hash(word);
    node *p = table[hash_index];

    while (p != NULL)
    {
        if (strcasecmp(p->word, word) == 0)
        {
            return true;
        }
        p = p->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        sum += word[i] ^ i;
    }
    return sum % N;

    // ChatGPT suggested hash function, used for testing purposes only
    /* unsigned int hash = 0; */
    /* for (int i = 0; word[i] != '\0'; i++) */
    /* { */
    /*     hash = (hash << 2) ^ word[i]; */
    /* } */
    /* return hash % N; */
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH+1];
    unsigned int hash_index = 0;
    while (fscanf(dict, "%s\n", word) > 0)
    {
        hash_index = hash(word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        if (table[hash_index] == NULL)
        {
            table[hash_index] = n;
            table[hash_index]->next = NULL;
        }
        else
        {
            n->next = table[hash_index];
            table[hash_index] = n;
        }

        for (int i = 0, j = strlen(word); i < j; i++)
        {
            table[hash_index]->word[i] = word[i];
        }
        table[hash_index]->word[strlen(word)] = '\0';
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size = 0;
    node *trav = NULL;
    for (int i = 0; i < N; i++)
    {
        trav = table[i];
        while (trav != NULL)
        {

            size++;
            trav = trav->next;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            free_linked_list(table[i]);
        }
    }
    return true;
}

void free_linked_list(node *n)
{
    if (n == NULL)
    {
        return;
    }

    free_linked_list(n->next);

    free(n);
    return;
}
