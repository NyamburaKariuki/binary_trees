#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: pointer to the node to find the uncle.
 *  Return:  pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;
	binary_tree_t *parent = (node != NULL ? node->parent : NULL);

	if ((parent != NULL) && (parent->parent != NULL))
	{
		right = parent->parent->right;
		left = parent->parent->left;
	}
	return (left == parent ? right : left);
}
