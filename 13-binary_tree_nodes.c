#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_nodes - finds the nodes of a binary tree
 * with only one leaf
 *
 * @tree: the tree to check
 *
 * Return: the nodes of the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes;

	nodes = 0;
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		nodes = 1;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
