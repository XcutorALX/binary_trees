#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_root - checks if a binary tree node is the root
 *
 * @node: the node to check
 *
 * Return: 1 if root, else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
