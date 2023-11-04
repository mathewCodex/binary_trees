#include "binary_trees.h"
/**
 * binary_tree_size - func that return the size of a tree
 * @tree: tree to check
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, rgt = 0, lft = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lft = binary_tree_size(tree->left);
		rgt = binary_tree_size(tree->right);
		size = rgt + lft + 1;
	}
	return (size);
}
