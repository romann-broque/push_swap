/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 15:39:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nb_from_index(t_list *stack, const size_t index)
{
	size_t	i;

	i = 0;
	while (stack != NULL && i < index)
	{
		++i;
		stack = stack->next;
	}
	return (((t_stack *)(stack->content))->nb);
}

static void	push_index_to_b(t_dualstack *dual, const size_t index)
{
	const int		nb = get_nb_from_index(dual->a, index);
	const size_t	half_size = ft_lstsize(dual->a) / 2;
	t_stack			*curr_stack;

	curr_stack = (dual->a->content);
	while (curr_stack->nb != nb)
	{
		if (index <= half_size)
			ra(dual);
		else
			rra(dual);
		print_dualstack(dual);
		curr_stack = (dual->a->content);
	}
	pb(dual);
	print_dualstack(dual);
}

static void	stack_op(t_dualstack *dual, const int content)
{
	const size_t	index = get_nb_index(dual->a, content);

	push_index_to_b(dual, index);
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

void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
	print_dualstack(dual);
	fact_instructions(dual->instructions);
}
