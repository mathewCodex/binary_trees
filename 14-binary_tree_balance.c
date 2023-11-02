#include "binary_trees.h"

/**
 * binary_tree_heigh_bal - determine the height of a BT for a balance tree
 * @tree: *****
 * Return: height
 */

size_t binary_tree_height_bal(const binary_tree_t *tree)
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
			lft = tree->left ? 1 + binary_tree_height_bal(tree->left) : 1;
			rgt = tree->right ? 1 + binary_tree_height_bal(tree->right) : 1;
		}
		return ((lft > rgt) ? lft : rgt);
	}
}

/**
 * binary_tree_balance - deter bal factor of a binary tree
 * @tree: tree to go thru
 * Return: bakanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_bal(tree->left));
		right = ((int)binary_tree_height_bal(tree->right));
		total = left - right;
	}
	return (total);
}
