/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:19:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 18:30:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_tree	*create_root(const int nb)
{
	t_tree	*root;

	root = (t_tree *)malloc(sizeof(t_tree));
	if (root != NULL)
	{
		root->content = nb;
		root->left = NULL;
		root->right = NULL;
	}
	return (root);
}

static void	add_node(t_tree **root, int nb)
{
	if (*root == NULL)
		*root = create_root(nb);
	else
	{
		if (nb < (*root)->content)
			add_node(&((*root)->left), nb);
		else
			add_node(&((*root)->right), nb);
	}
}

t_tree	*create_tree(t_list *stack)
{
	t_tree	*tree;

	tree = NULL;
	while (stack != NULL)
	{
		add_node(&tree, ((t_stack *)(stack->content))->nb);
		stack = stack->next;
	}
	return (tree);
}

void	clear_tree(t_tree *tree)
{
	if (tree != NULL)
	{
		clear_tree(tree->left);
		clear_tree(tree->right);
		free(tree);
	}
}

void	display_tree(t_tree *root)
{
	if (root->left != NULL)
		display_tree(root->left);
	printf("%d\n", root->content);
	if (root->right != NULL)
		display_tree(root->right);
}
