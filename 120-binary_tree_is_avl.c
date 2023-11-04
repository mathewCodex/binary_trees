#include "binary_trees.h"

/**
 * binary_tree_height - func that measure height of BT
 * @tree: ***
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
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
			lft = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			rgt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((lft > rgt) ? lft : rgt);
		}
}
/**
 * bal_avl - aux func to cmp each subtree if its AVL
 * @tree: node that point to tree to check
 * @high: node that points to heigher
 * @lower: likewise
 * Return: 1 if AVL opps if not
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_l, height_r, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		balancer = height_l > height_r ? height_l - height_r : height_r - height_l;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
				bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a bT is a valid AVL tree
 * @tree: ***
 * Return: 1 if AVL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
