#include "binary_trees.h"

/**
 * binary_tree_preorder - print elem of tree using pre-order traversal
 * @tree: tree to go thru
 * @func: func to use
 * Return: none;
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func) (int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
