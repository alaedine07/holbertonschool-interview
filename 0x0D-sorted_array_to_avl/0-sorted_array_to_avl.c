#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
* @parent: pointer to the parent node of the node to create
* @value: the value to put in the new node
* Return: binary tree
*/
avl_t *binary_tree_node(avl_t *parent, int value)
{
	avl_t *tmp = malloc(sizeof(avl_t));

	if (tmp == NULL)
	{
		return (NULL);
	}

	tmp->n = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = parent;
	return (tmp);
}
/**
* insert_node - recursive nodes insertion
* @root: pointer to the parent node of the node to create
* @array: point the first element of the array
* @left: index to the array left side
* @right: index to the array right side
* Return: avl tree
*/
avl_t *insert_node(avl_t *root, int *array, int left, int right)
{
	avl_t *tmp;
	int i;

	if (left > right)
	{
		return (NULL);
	}
	i = (right + left) / 2;
	tmp = binary_tree_node(root, array[i]);
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp->left = insert_node(tmp, array, left, i - 1);
	tmp->right = insert_node(tmp, array, i + 1, right);
	return (tmp);
}

/**
 * sorted_array_to_avl - builds an AVL tree from sorted array
 * @array: Is a pointer to the first element of the array
 * @size: Is the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t left, right;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}
	left = 0;
	right = size - 1;
	root = insert_node(root, array, left, right);
	return (root);
}
