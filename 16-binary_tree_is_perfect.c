#include "binary_trees.h"

/**
 * tree_s - function that computes some statistics about a binary tree.
 * @tree: pointer to the root node of the tree to check.
 * @n: accumulated height of the current path in the tree.
 * @lves: pointer to the tree's leaf count value.
 * @ht: pointer to the tree's maximum height value.
 *
 * Return: no return.
 */
void tree_s(const binary_tree_t *tree, size_t n,
	size_t *lves, size_t *ht)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (lves != NULL)
				(*lves)++;
			if ((ht != NULL) && (n > *ht))
				*ht = n;
		}
		else
		{
			tree_s(tree->left, n + 1, lves, ht);
			tree_s(tree->right, n + 1, lves, ht);
		}
	}
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full. 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lves_count = 0;
	size_t tree_ht = 0;

	tree_s(tree, 0, &lves_count, &tree_ht);
	return ((int)lves_count == (1 << tree_ht) ? 1 : 0);
}
