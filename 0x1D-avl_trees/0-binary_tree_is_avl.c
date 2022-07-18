#include "binary_trees.h"

/**
 * binary_tree_is_avl_recursion - Returns the depth of a binary tree
 *
 * @tree: A binary tree
 *
 * Return: Depth of `tree` or FAIL on failure
 */
int binary_tree_is_avl_recursion(const binary_tree_t *tree)
{
	int left_subtree_height, right_subtree_height;

	if (!tree)
		return (0);

	/* Check for valid binary search tree */
	if (
		(tree->left && tree->left->n > tree->n) ||
		(tree->right && tree->right->n < tree->n)
	)
		return (FAIL);

	left_subtree_height = binary_tree_is_avl_recursion(tree->left);
	if (left_subtree_height == FAIL)
		return (FAIL);
	right_subtree_height = binary_tree_is_avl_recursion(tree->right);
	if (right_subtree_height == FAIL)
		return (FAIL);

	if (left_subtree_height - right_subtree_height > 1 ||
		right_subtree_height - left_subtree_height > 1)
		return (FAIL);

	return (left_subtree_height > right_subtree_height ?
		left_subtree_height + 1 :
		right_subtree_height + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: A binary tree to test
 *
 * Return: 1 if `tree` is an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (binary_tree_is_avl_recursion(tree) == FAIL)
		return (FALSE);
	return (TRUE);
}
