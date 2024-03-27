#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_sibling - finds the sig=bling of a node
 *
 * @node: the node
 *
 * Return: tje sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent->left == NULL || parent->right == NULL)
		return (NULL);

	if (parent->left == node)
		return (parent->right);

	return (parent->left);
}
