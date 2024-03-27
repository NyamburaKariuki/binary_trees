#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *temp = NULL;

	if (tree != NULL)
	{
		temp = tree->parent;
		while (temp != NULL)
		{
			depth++;
			temp = temp->parent;
		}
	}
	return (depth);
}
