#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * checkHeight - Check the height of a binary tree
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
*/
static size_t checkHeight(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	h_left = tree->left ? 1 + checkHeight(tree->left) : 0;
	h_right = tree->right ? 1 + checkHeight(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * preorderTraversal - goes through a binary tree
 *                     using pre-order traversal
 * @root: pointer root of the tree
 * @node: pointer node in the tree
 * @h: height of tree
 * @l: layer on the tree
*/
void preorderTraversal(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		preorderTraversal(root->left, node, h, l);
	if (root->right)
		preorderTraversal(root->right, node, h, l);
}

/**
 * sort - binary tree Heap Sort
 * @tmp: pointer to the heap root
 * Return: pointer to last node
*/
heap_t *sort(heap_t *tmp)
{
	int n;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			n = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = n;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			n = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = n;
			tmp = tmp->right;
		}

	}
	return (tmp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root of the heap
 * Return: the value stored in the root node, or 0.
*/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	preorderTraversal(tmp, &node, checkHeight(tmp), 0);
	tmp = sort(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
