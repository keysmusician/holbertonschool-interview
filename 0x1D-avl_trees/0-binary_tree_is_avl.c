#include "binary_trees.h"

/**
 * binary_tree_is_avl_recursion - Determines if a binary tree is an AVL tree
 *
 * @tree: A binary tree
 * @tree_info: A `tree_info` struct containing information about the tree
 *
 * Return: Information relevant to the AVL tree status
 */
tree_info_t binary_tree_is_avl_recursion(
		const binary_tree_t *tree, tree_info_t tree_info)
{
	tree_info_t left_subtree_info, right_subtree_info;

	tree_info.height = 0;
	if (!tree || tree_info.is_AVL == FALSE)
		return (tree_info);

	left_subtree_info = binary_tree_is_avl_recursion(tree->left, tree_info);
	if (left_subtree_info.is_AVL == FALSE)
		return (left_subtree_info);
	right_subtree_info = binary_tree_is_avl_recursion(tree->right, tree_info);
	if (right_subtree_info.is_AVL == FALSE)
		return (right_subtree_info);

	if (left_subtree_info.height - right_subtree_info.height > 1 ||
		right_subtree_info.height - left_subtree_info.height > 1
	) /* Check subtree heights differ by no more than 1 */
		tree_info.is_AVL = FALSE;
	else
		tree_info.height =
			left_subtree_info.height > right_subtree_info.height ?
			left_subtree_info.height + 1 : right_subtree_info.height + 1;
		tree_info.max = tree->n;
		tree_info.min = tree->n;
		if (tree->left)/* Check for valid binary search tree */
		{
			if (left_subtree_info.max > tree->n)
				tree_info.is_AVL = FALSE;
			tree_info.min = left_subtree_info.min;
		}
		if (tree->right)
		{
			if (right_subtree_info.min < tree->n)
				tree_info.is_AVL = FALSE;
			tree_info.max = right_subtree_info.max;
		}

	return (tree_info);
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
	tree_info_t tree_info;

	tree_info.is_AVL = TRUE;

	if (binary_tree_is_avl_recursion(tree, tree_info).is_AVL == FALSE)
		return (FALSE);
	return (TRUE);
}
