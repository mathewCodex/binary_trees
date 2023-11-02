#include "binary_trees.h"

/**
 * binary_tree_insert_right - Like the left node its perform the opps
 * of adding a right node to the if existing parent node and move down
 * one level to add the new node first
 * @parent: parent
 * @value: val of node
 * Return: NULL if it fails or the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
