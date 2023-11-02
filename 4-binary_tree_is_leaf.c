#include "binary_trees.h"

/**
 * binary_tree_is_leaf - determine if a node is a leaf meaning theres no child
 * at right nor left
 * @node: node to study
 * Return: 1 else  0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
