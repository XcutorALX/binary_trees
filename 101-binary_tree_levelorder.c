#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * enqueue - adds a node to a queue
 *
 * @node: the node to be added
 * @queue: the queue to be edited
 *
 * Return: 1 on success 0 on failure
 */
int enqueue(binary_tree_t *node, queue_t **queue)
{
	node_t *prev, *new;

	new = malloc(sizeof(node_t));
	new->bt_node = node;
	new->next = NULL;

	if (*queue == NULL)
	{
		*queue = malloc(sizeof(queue_t));
		(*queue)->head = new;
		(*queue)->tail = new;
		return (1);
	}
	else if ((*queue)->head == NULL)
	{
		(*queue)->head = new;
		(*queue)->tail = new;
	}

	prev = (*queue)->tail;
	prev->next = new;
	(*queue)->tail = new;
	return (1);
}


/**
 * dequeue - pops a node from a queue
 *
 * @queue: the queue to be edited
 *
 * Return: 1 on success 0 on failure
 */
int dequeue(queue_t *queue)
{
	node_t *prev;

	if (queue == NULL || queue->head == NULL)
		return (0);

	if (queue->tail == queue->head)
	{
		free(queue->head);
		queue->head = NULL;
		queue->tail = NULL;
		return (1);
	}
	prev = queue->head;
	queue->head = queue->head->next;
	free(prev);
	return (1);
}

/**
 * binary_tree_levelorder - traverses a
 * binary tree using level order traversal
 *
 * @tree: the tree to be traversed
 * @func: the function to be called on the nodes
 *
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current;
	queue_t *queue;
	int result;


	if (tree == NULL)
		return;

	queue = malloc(sizeof(queue_t));
	queue->head = NULL;
	queue->tail = NULL;
	current = (binary_tree_t *)tree;
	result = enqueue(current, &queue);
	if (!result)
		return;
	while (queue->head != NULL)
	{
		current = queue->head->bt_node;
		func(current->n);
		result = current->left && enqueue(current->left, &queue);
		result = current->right && enqueue(current->right, &queue);
		dequeue(queue);
	}
}
