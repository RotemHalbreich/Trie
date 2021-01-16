#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int main(int argc, char **argv)
{
    int temp;
    scanf("%d", &temp);

    char *input;
    input = (char *)malloc(sizeof(char) * 16);
    struct Trie *head = getNewTrieNode();
    int input_len = 10;
    append_to_input(input, head, input_len);

    if (argc == 2 && argv[1][0] == 'r')
    {
        free_str_reverse(head, 0);
    }
    else
    {
        free_str(head, 0);
    }
    delete (head);
    return 0;
}
