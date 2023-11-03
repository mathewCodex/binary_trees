#include "binary_trees.h"
/**
 * check_left_sub_tree - check if all  node are smaller than
 * the root specifired
 * @node: node in the tree to verify condition
 * @max: val to compare
 * Return: 1 if all node are smaller or equal
 */
int check_left_sub_tree(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_left_sub_tree(node->left, max);
		right = check_left_sub_tree(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * check_right_sub_tree - check for the node bigger than the root
 * @node: node to verify
 * @min: val to cmpare
 * Return: 1 if bigger -0 if not
 */
int check_right_sub_tree(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_right_sub_tree(node->left, min);
		right = check_right_sub_tree(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - tell if a tree is a bst
 * its works by first verifying the left and the right node
 * to know which is smaller or bigger in the root
 * after the verification it checks if the left subtree has a small node than
 * the right
 * @tree: node that point to tree
 * Return: 1if true
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_left_sub_tree(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_right_sub_tree(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
