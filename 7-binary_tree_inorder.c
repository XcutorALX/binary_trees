#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_inorder - goes througha binary tree using the
 * inorder traversal
 *
 * @tree: the tree to go through
 * @func: the function to call for each node
 *
 * Return: None
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
