#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_size - finds the size of a binary tree\
 *
 * @tree: the tree to check
 *
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}
