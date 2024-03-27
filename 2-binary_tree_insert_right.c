#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent != NULL)
	{
		new_node = malloc(sizeof(binary_tree_t));

		if (new_node != NULL)
		{
			new_node->n = value;
			new_node->parent = parent;
			new_node->right = parent->right;
			new_node->left = NULL;

			if (parent->right != NULL)
				parent->right->parent = new_node;
			parent->right = new_node;
		}
	}
	return (new_node);
}
