/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 18:15:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_op(t_dualstack *dual, int content)
{
	const int	index = get_nb_index(dual->a, content);
	const int	half_size = ft_lstsize(dual->a) / 2;

	while (*((int *)(dual->a->content)) != content)
	{
		if (index <= half_size)
			ra(dual);
		else
			rra(dual);
	}
	pb(dual);
}

static void	infix_sort(t_dualstack *dual, t_tree *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			infix_sort(dual, root->left);
		stack_op(dual, root->content);
		if (root->right != NULL)
			infix_sort(dual, root->right);
	}
}

static void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
}

t_tree	*find_node(t_tree *root, int nb)
{
	t_tree	*node;

	if (root == NULL)
		return (NULL);
	if (root->content == nb)
		return (root);
	node = find_node(root->left, nb);
	if (node != NULL)
		return (node);
	node = find_node(root->right, nb);
	return (node);
}

static void	set_index(t_tree *root, t_list **stack, size_t *index)
{
	size_t	*curr_index;

	curr_index = (size_t *)malloc(sizeof(size_t));
	if (root != NULL)
	{
		set_index(root->left, stack, index);
		++(*index);
		*curr_index = *index;
		ft_contadd_back(stack, curr_index);
		set_index(root->right, stack, index);
	}
}

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;
	size_t	index_init;
	t_list	*index;

	tree = create_tree(dual->a);
	display_tree(tree);
	tree_sort(dual, tree);
//
	index_init = 0;
	index = NULL;
	set_index(tree, &index, &index_init);
	ft_lstprint(index);
//
	fact_instructions(dual->instructions);
	print_instructions(dual->instructions);
	clear_tree(tree);
}
