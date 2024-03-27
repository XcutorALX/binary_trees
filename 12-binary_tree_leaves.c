#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_leaves - finds the leaves of a binary tree\
 *
 * @tree: the tree to check
 *
 * Return: the leaves of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	return (left + right);
}
