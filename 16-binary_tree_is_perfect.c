#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: the binary tree
 *
 * Return: 1 if true, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result;
	size_t height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	height += binary_tree_depth(tree);

	result = is_perfect_recursive(tree, height);
	return (result);
}

/**
 * is_perfect_recursive - recursive function for binary_tree_is_perfect
 *
 * @tree: the tree
 * @height: the height of the tree
 *
 * Return: 1 if perfect, otherwise 0
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t height)
{
	size_t depth;
	int result;

	if (tree->left != NULL && tree->right != NULL)
	{
		result = is_perfect_recursive(tree->left, height) &&
			is_perfect_recursive(tree->right, height);
		return (result);
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		depth = binary_tree_depth(tree);
		return (depth == height);
	}
	else
	{
		return (0);
	}
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

/**
 * binary_tree_depth - finds the depth of a binary tree\
 *
 * @tree: the tree to check
 *
 * Return: the size of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}
