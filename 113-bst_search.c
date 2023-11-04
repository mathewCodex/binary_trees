#include "binary_trees.h"
/**
 * bst_search - search for a special val in the tree
 * @tree: tree to search
 * @value: value
 * Return:  node with value else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *f;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		f = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		f = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (f);
}
