#include "binary_trees.h"
#include <stdlib.h>

/**
 * local_height - Measures the height of a subtree in edges
 * @tree: Pointer to the subtree root
 * Return: Height in edges, 0 if tree is NULL or leaf
 */

static size_t local_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = (tree->left) ? local_height(tree->left) + 1 : 0;
	right_height = (tree->right) ? local_height(tree->right) + 1 : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = (tree->left) ? local_height(tree->left) + 1 : 0;
	right_height = (tree->right) ? local_height(tree->right) + 1 : 0;

	return ((int)left_height - (int)right_height);
}
