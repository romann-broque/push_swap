/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:03:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/10 15:27:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_top_a(t_dualstack *dual, const size_t index)
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
//		print_dualstack(dual);
		curr_stack = (dual->a->content);
	}
}

static void	put_top_b(t_dualstack *dual, const size_t index)
{
	const int		nb = get_nb_from_index(dual->b, index);
	const size_t	half_size = ft_lstsize(dual->b) / 2;
	t_stack			*curr_stack;

	curr_stack = (dual->b->content);
	while (curr_stack->nb != nb)
	{
		if (index <= half_size)
			rb(dual);
		else
			rrb(dual);
//		print_dualstack(dual);
		curr_stack = (dual->b->content);
	}
}

void	push_index_to_b(t_dualstack *dual, const size_t index)
{
	put_top_a(dual, index);
	pb(dual);
	//print_dualstack(dual);
}

void	push_index_to_a(t_dualstack *dual, const size_t index)
{
	put_top_b(dual, index);
	if (dual->a != NULL)
		put_top_a(dual, get_next_index_from_index(dual->a, index));
	pa(dual);
	//print_dualstack(dual);
}
