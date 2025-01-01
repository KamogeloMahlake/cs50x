// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int count = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    node *current_node = table[index];
    while (current_node != NULL)
    {
        if (strcasecmp(current_node->word, word) == 0)
        {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char buffer[LENGTH + 1];

    while (fscanf(source, "%s", buffer) != EOF)
    {
        node *item = malloc(sizeof(node));
        if (item == NULL)
        {
            return false;
        }
        unsigned int index = hash(buffer);
        strcpy(item->word, buffer);
        item->next = NULL;
        if (table[index] != NULL)
        {
            item->next = table[index];
        }
        table[index] = item;
        count++;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
}
