#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of the tree
 * @tree:pointer to the root node of the tree
 * Return: 0 if tree is NULL else the depth
 */
size_t binary_tree_depth(const heap_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
/**
 * binary_tree_height - measures the hight of the tree
 * @tree:pointer to the root node of the tree
 * Return: 0 if tree is NULL else the hight
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t h_left, h_right;

	if (tree == NULL)
		return (0);
	/* check if node is leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_right <= h_left)
		return (h_left + 1);

	return (h_right + 1);
}
/**
* insert - function to insert node
* @tree: pointer to tree
* @level: level to insert node
* @value: value of the new node
* Return: the node inserted
*/
binary_tree_t *insert(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (tree != NULL && tree->left == NULL && tree->right == NULL)
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = insert(tree->left, level, value);
	if (left == NULL)
		right = insert(tree->right, level, value);
	else
		return (left);
	return (right);
}
/**
 * heapify - transform binary tree to MAX-heap
 * @node: node to start
 * Return: pointer to starting node
 */
heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root:double pointer to the root node of the Heap
 * @value:  value to store in the node to be inserted
 * Return: pointer to inserted node or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t level, i = 0;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *)*root, value);
		return (*root);
	}
	level = binary_tree_height(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *)insert((binary_tree_t *)*root, i, value);
		if (node != NULL)
			break;
	}
	node = heapify(node);
	return (node);
}
