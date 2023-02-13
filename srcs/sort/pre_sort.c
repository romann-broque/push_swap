/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:00:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/13 10:35:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_max_rank(t_list *stack)
{
	size_t	max_rank;

	max_rank = 0;
	while (stack != NULL)
	{
		if (max_rank < ((t_stack *)(stack->content))->rank)
			max_rank = ((t_stack *)(stack->content))->rank;
		stack = stack->next;
	}
	return (max_rank);
}

size_t	get_min_rank(t_list *stack)
{
	size_t	min_rank;

	min_rank = SIZE_MAX;
	while (stack != NULL)
	{
		if (min_rank > ((t_stack *)(stack->content))->rank)
			min_rank = ((t_stack *)(stack->content))->rank;
		stack = stack->next;
	}
	return (min_rank);
}

void	pre_sort(t_dualstack *dual)
{
	const size_t	max_rank = ft_lstsize(dual->a);
	size_t			curr_min_rank;
	size_t			part;
	t_stack			*stack;

	part = 1;
	while (dual->a != NULL)
	{
		stack = (t_stack *)(dual->a->content);
		curr_min_rank = get_min_rank(dual->a);
		if (stack->rank <= (part * max_rank) / 4)
			pb(dual);
		else if (part < 4 && curr_min_rank > (part * max_rank) / 4)
			++part;
		ra(dual);
	}
	infix_sort_rev(dual, dual->tree);
}
