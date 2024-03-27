#include "binary_trees.h"
#include <stddef.h>

/**
 * ancestor_recursive - finds the lowest common ancestor of two nodes
 *
 * @first: the first node
 * @second: the second node
 *
 * Return: the common ancestor
 */
binary_tree_t *ancestor_recursive(binary_tree_t *first, binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth != second_depth &&
			first != NULL && second != NULL)
	{
		if (first_depth > second_depth)
		{
			first = first->parent;
			first_depth--;
		}
		else if (second_depth > first_depth)
		{
			second = second->parent;
			second_depth--;
		}
	}

	if (first == second)
		return (first);

	return (ancestor_recursive(first->parent,
				second->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 *
 * @first: the first node
 * @second: the second node
 *
 * Return: pointer to the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return (first->parent);

	return (ancestor_recursive((binary_tree_t *)first, (binary_tree_t *)second));
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
