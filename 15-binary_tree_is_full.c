#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: the binary tree
 *
 * Return: 1 if full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full;

	if (tree == NULL)
		return (0);

	full = is_full_recursive(tree);
	return (full == 0);
}

/**
 * is_full_recursive - recursively check through binary tree
 *
 * @tree: the tree to check
 *
 * Return: an int
 */
int is_full_recursive(const binary_tree_t *tree)
{
	int full;

	full = 0;
	if ((tree->left != NULL && tree->right == NULL) ||
			(tree->right != NULL && tree->left == NULL))
	{
		return (1);
	}
	else if (tree->left == NULL && tree->right == NULL)
		return (0);

	full += is_full_recursive(tree->left);
	full += is_full_recursive(tree->right);

	return (full);
}
