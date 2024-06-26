#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_height - finds the height of a binary tree\
 *
 * @tree: the tree to check
 *
 * Return: the size of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree != NULL &&
		tree->left == NULL &&
		tree->right == NULL)
		return (0);

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
