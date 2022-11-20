#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct Trie - trie struct
 * @children: array of child nodes
 * @word: 1 if is word
 * @count: how many instances of this word
 * @left: how many instances left to find
 * @val: pointer to word
 */
typedef struct Trie
{
	struct Trie *children[26];
	int word;
	int count;
	int left;
	char *val;
} Trie;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
