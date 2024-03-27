#include "binary_trees.h"

/**
 * node_ht - computes the height of a binary tree's node.
 * @tree: pointer to the root node of the tree to measure the height.
 * @n: accumulated height.
 * @height: pointer to the maximum height in the node's tree.
 *
 * Return: no return.
 */
void node_ht(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			node_ht(tree->left, n + 1, height);
			node_ht(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_balance - measures the balance factor of * a binary tree.
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of a binary tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_fct = 0, left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (0);

	node_ht(tree->left, 1, &left_ht);
	node_ht(tree->right, 1, &right_ht);

	balance_fct = left_ht - right_ht;
	return (balance_fct);
}
