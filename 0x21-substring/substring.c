#include "substring.h"

#define INDEX(x) ((x) - 'a')

/**
 * free_trie - frees all nodes of trie
 * @root: pointer to root
 */
void free_trie(Trie *root)
{
	int i = 0;

	for (i = 0; i < 26; i++)
		if (root->children[i])
			free_trie(root->children[i]);
	free(root);
}

/**
 * search_trie - searches trie for word
 * @node: root of tree
 * @str: string to find
 * @k: characters of str to find
 * @memo: the memoization array
 * @j: index in memo
 * Return: 1 if found else 0
 */
int search_trie(Trie *node, char *str, int k, Trie **memo, int j)
{
	for (; k; str++, k--)
	{
		if (!node->children[INDEX(*str)])
			return (0);
		node = node->children[INDEX(*str)];
	}

	memo[j] = node;
	if (node->left-- > 0)
	{
		return (1);
	}
	return (0);
}

/**
 * make_trie - fills trie with words
 * @root: pointer to root of trie
 * @words: pointer to array of words
 * @nb_words: number of words
 * @nodes: array of trie nodes to populate
 */
void make_trie(Trie *root, char const **words, int nb_words, Trie **nodes)
{
	int i = 0;
	char const *str;
	Trie *node;

	for (i = 0; i < nb_words; i++)
	{
		node = root;
		for (str = words[i]; *str; str++)
		{
			if (!node->children[INDEX(*str)])
			{
				node->children[INDEX(*str)] = calloc(1, sizeof(Trie));
				if (!node->children[INDEX(*str)])
					exit(1);
			}
			node = node->children[INDEX(*str)];
		}
		node->word = 1;
		node->count++;
		node->left++;
		node->val = (char *)words[i];
		nodes[i] = node;
	}
}
/**
 * find_substring - finds substring composed of all concatenated words
 * @s: the string to search
 * @words: array of contentated words to find
 * @nb_words: the size of passed array
 * @n: size of return array, to set
 * Return: array of indices where all words found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, j, k, slen, matches;
	Trie *root, **nodes, **memo;
	int *indices;

	*n = 0;
	slen = strlen(s);
	k = strlen(words[0]);
	indices = calloc(slen, sizeof(int));
	root = calloc(1, sizeof(Trie));
	nodes = calloc(nb_words, sizeof(*nodes));
	memo = calloc(slen, sizeof(*memo));
	if (!indices || !root || !nodes || !memo)
		exit(1);
	make_trie(root, words, nb_words, nodes);

	for (i = 0; i < slen; i++)
	{
		matches = 0;
		for (j = i; j <= slen - k; j += k)
		{
			if ((memo[j] && memo[j]->left-- > 0) ||
				search_trie(root, (char *)s + j, k, memo, j))
			{
				if (++matches == nb_words)
				{
					indices[*n] = i;
					*n += 1;
					break;
				}
			}
			else
				break;
		}
		for (j = 0; j < nb_words; j++)
			nodes[j]->left = nodes[j]->count;
	}
	free_trie(root), free(nodes), free(memo);
	if (*n == 0)
		indices = (free(indices), NULL);
	return (indices);
}
