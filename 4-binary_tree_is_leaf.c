#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_leaf - checks if a binary tree node
 * is a leaf
 *
 * @node: the node to check
 *
 * Return: 1 if leaf and 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->left == NULL
			&& node->right == NULL);
}
