#include "binary_trees.h"

/**
 * binary_tree_is_root - func that check if a node is a root
 * @node: Node to check
 * Return: 0 if not 1 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
