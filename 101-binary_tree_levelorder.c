#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a BT
 * @tree: tree to go through
 * Return: heught of BT
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lft = 0;
	size_t rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rgt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lft > rgt) ? lft : rgt);
	}
}
/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check depth
 * Return: 0 if it is the root numb
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 : binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - function make a linked list from depth level and node
 * @head: ptr to head
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if  (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}
/**
 * recursion - goes thru the complete tree and each stores each node
 * @head: ptr to head
 * @tree: ptr to head
 * Return: nothing by default
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the node elem in a level-order
 * @tree: roo node
 * @func: func to use
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
