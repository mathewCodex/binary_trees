#include "binary_trees.h"

/**
 * binary_tree_inorder - print elem of tree using inorder traversal
 * @tree: tree to go thru
 * @func: func to use
 * Return: none
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
