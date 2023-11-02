#include "binary_trees.h"

/**
 * binary_tree_leaves - return the numb of leaves
 * @tree: tree to check
 * Return: numb of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, lft = 0, rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lft = binary_tree_leaves(tree->left);
		rgt = binary_tree_leaves(tree->right);
		leaf = lft  + rgt;
		return ((!lft && !rgt) ? leaf + 1 : leaf + 0);
	}
}
