#include "binary_trees.h"

/**
 * binary_tree_rotate_left - func that rotates left BT
 * @tree: root of the tree
 * Return: ptr node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
	{
		pivot->left->parent = tree;
	}
	pivot->left  = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
