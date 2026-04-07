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
 * local_size - Counts nodes in a binary subtree
 * @tree: Pointer to the subtree root
 * Return: Number of nodes
 */

static size_t local_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + local_size(tree->left) + local_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, expected_size;

	if (tree == NULL)
		return (0);

	height = local_height(tree);
	size = local_size(tree);
	expected_size = ((size_t)1 << (height + 1)) - 1;

	if (size == expected_size)
		return (1);
	else
		return (0);
}
