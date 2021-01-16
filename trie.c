#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


struct Trie
{
    int isLeaf;
    struct Trie *chars[CHAR_SIZE];
    int counter;
};

/// Function that returns a new Trie node
struct Trie *getNewTrieNode()
{
    struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie));
    node->isLeaf = 0;
    node->counter = 0;
    
    for (int i = 0; i < CHAR_SIZE; i++)
        node->chars[i] = NULL;

    return node;
}

/// Iterative function to insert a string in Trie
void insert(struct Trie *head, char *str)
{
    struct Trie *curr = head;
    while (*str)
    {
        if (curr->chars[*str - LOWER_A] == NULL)
            curr->chars[*str - LOWER_A] = getNewTrieNode();
        curr = curr->chars[*str - LOWER_A];
        str++;
    }
    curr->counter++;
    curr->isLeaf = 1;
}

/// Will build a word from input array and will insert to the trietree
void build_word(char input[], int src, int dest, struct Trie *head)
{

    if (src == dest)
        return;

    char *word = (char *)malloc(sizeof(char) * (dest - src + 2));
    int k = 0;
    for (int i = src; i < dest; ++i)
    {
        *(word + k) = input[i];
        k++;
    }
    if (k == 0)
        return;

    *(word + k) = '\0';

    insert(head, word);

    free(word);
}
int max_word = 0;

// Iterative function separated words from the buffer
void append_to_input(char *input, struct Trie *head, int input_len)
{
    int temp;
    int temp_max = 0;
    int temp_len = input_len;
    int i = 0;
    int j = 0;
    int k = 2;
 
    while ((temp = getchar()) != EOF)
    {
        if (temp >= LOWER_A && temp <= LOWER_Z)
        {
            *(input + i) = temp;
            i++;
            temp_max++;
        }
        else if (temp >= UPPER_A && temp <= UPPER_Z)
        {
            temp = temp + SPACE;
            *(input + i) = temp;
            temp_max++;
            i++;
        }
        else if (temp == SPACE || temp == ENTER || temp == TAB)
        {
            build_word(input, j, i, head);

            if (temp_max > max_word)
                max_word = temp_max;

            temp_max = 0;
            j = ++i;
        }
        if (i == temp_len)
        {
        TRY:;
            char *tmp;
            tmp = (char *)realloc(input, sizeof(char) + input_len * k);
            temp_len = input_len * k;
            k++;
            if (tmp != NULL)
                input = tmp;
            else
                goto TRY;
        }
    }
    build_word(input, j, i, head);

    free(input);
}

/// Will delete and free all the nodes in the tree
void delete (struct Trie *root)
{
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (root->chars[i])
            delete (root->chars[i]);
    }
    free(root);
}

/// Will dispaly all the words in the tree
void display(struct Trie *root, char str[], int level)
{
    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s %d\n", str, root->counter);
    }

    int i;
    for (i = 0; i < CHAR_SIZE; i++)
    {
        if (root->chars[i])
        {
            str[level] = i + LOWER_A;
            display(root->chars[i], str, level + 1);
        }
    }
}

/// Will reverse dispaly all the words in the tree
void display_reverse(struct Trie *root, char str[], int level)
{
    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s %d\n", str, root->counter);
    }
    for (int i = CHAR_SIZE - 1; i >= 0; i--)
    {
        if (root->chars[i])
        {
            str[level] = i + LOWER_A;
            display_reverse(root->chars[i], str, level + 1);
        }
    }
}

/// Will call the display function and free str
void free_str(struct Trie *root, int level)
{
    char str[max_word + 1];
    display(root, str, level);
}

/// Will call the display_reverse function and free str
void free_str_reverse(struct Trie *root, int level)
{
    char str[max_word + 1];
    display_reverse(root, str, level);
}
