/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:00:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/17 23:07:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_min_rank(t_list *stack)
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

void	pre_sort(t_dualstack *dual, const size_t part_count)
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
		if (stack->rank <= ((part + 1) * max_rank) / part_count)
		{
			pb(dual);
			if (stack->rank >= (part * max_rank) / part_count)
				rb(dual);
		}
		else if (part < part_count && curr_min_rank > (part * max_rank) / part_count)
			++part;
		else
			ra(dual);
	}
	infix_sort_rev(dual, dual->tree);
}
