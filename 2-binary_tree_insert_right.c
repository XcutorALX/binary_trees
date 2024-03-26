#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a new
 * node into the right branch of a binary tree
 *
 *@parent: the parent of the node being created
 *@value: the value to be stored in the node
 *
 * Return: a pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *temp;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;

	if (parent->right == NULL)
		parent->right = new;
	else
	{
		temp = parent->right;
		temp->parent = new;
		parent->right = new;
		new->right = temp;
	}

	return (new);
}
