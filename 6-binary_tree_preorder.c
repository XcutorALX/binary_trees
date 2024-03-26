#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_preorder - goes througha binary tree using the
 * preorder traversal
 *
 * @tree: the tree to go through
 * @func: the function to call for each node
 *
 * Return: None
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
