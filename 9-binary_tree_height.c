#include "binary_trees.h"

/**
 * binary_tree_height - func that measures the height of a binary tree
 * @tree: tree to go thru
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lft =  0;
	size_t rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lft = tree->left ? 1 + binary_tree_height(tree->left)  :  0;
			rgt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((rgt > 1) ? lft : rgt);
	}
}
