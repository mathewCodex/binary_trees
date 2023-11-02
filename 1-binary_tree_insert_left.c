#include "binary_trees.h"

/**
 * binary_tree_insert_left - This function
 * adds a node in the left of the parent
 * iftheres a parent it moves one level and add the new node first
 * @parent: parent of a particular node
 * @value: val of node
 * Return: NUll if it fails
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
