#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_balance - measures the balance factor of a binary treee
 *
 * @tree: the tree to measure on
 *
 * Return: the balance factor, or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}

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

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
