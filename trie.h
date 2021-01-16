#ifndef TRIE_H
#define TRIE_H

#define CHAR_SIZE 26
#define UPPER_A 65
#define UPPER_Z 90
#define LOWER_A 97
#define LOWER_Z 122
#define ENTER '\n'
#define SPACE ' '
#define TAB '\t'

struct Trie;
struct Trie *getNewTrieNode();

void insert(struct Trie *head, char *str);

void build_word(char input[], int start, int end, struct Trie *head);

void append_to_input(char *input, struct Trie *head, int input_len);

void display(struct Trie *root, char str[], int level);

void display_reverse(struct Trie *root, char str[], int level);

void free_str(struct Trie *root, int level);

void free_str_reverse(struct Trie *root, int level);

void delete (struct Trie *root);

#endif //TRIE_H
