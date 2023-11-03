#include "binary_trees.h"
/**
 * new_node - func that creates a new_node
 * @node: type ptr of node
 * Return: node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}
/**
 * free_node - function that free the node
 * @head: node of the LL
 */
void free_node(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}
/**
 * _push - function to node into stack
 * @node: type of ptr nodr tree
 * @head: type of head node in the stack
 * @tail: tail node in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_node(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 * _pop - pops a node into the stack
 * @head: type of head node in the stack
 */
void _pop(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}
/**
 * binary_tree_is_complete - functionthat checks for a complete BT
 * @tree: type of ptr of node tree
 * Return: 1if is complete  0otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_node(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_node(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
