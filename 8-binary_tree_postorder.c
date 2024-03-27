#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_postorder - goes througha binary tree using the
 * postorder traversal
 *
 * @tree: the tree to go through
 * @func: the function to call for each node
 *
 * Return: None
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
