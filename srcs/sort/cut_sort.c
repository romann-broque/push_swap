/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:00:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:10:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_min_rank(t_list *stack)
{
	size_t	min_rank;
	size_t	curr_rank;

	min_rank = SIZE_MAX;
	while (stack != NULL)
	{
		curr_rank = get_rank(stack);
		if (min_rank > curr_rank)
			min_rank = curr_rank;
		stack = stack->next;
	}
	return (min_rank);
}

static void	cut_sort_op(
	t_dualstack	*dual,
	const size_t part_count,
	void (*rot_fct)(t_dualstack *))
{
	const size_t	max_rank = ft_lstsize(dual->a);
	size_t			curr_min_rank;
	size_t			part;
	t_stack			*stack;

	part = 1;
	while (dual->a != NULL)
	{
		stack = dual->a->content;
		curr_min_rank = get_min_rank(dual->a);
		if (stack->rank <= ((part + 1) * max_rank) / part_count)
		{
			pb(dual);
			if (stack->rank >= (part * max_rank) / part_count)
				rb(dual);
		}
		else if (part < part_count
			&& curr_min_rank > (part * max_rank) / part_count)
			++part;
		else
			rot_fct(dual);
	}
}

static void	cut_sort(t_dualstack *dual, void (*rot_fct)(t_dualstack *))
{
	const size_t	size = ft_lstsize(dual->a);
	const size_t	cut = (ft_log(size / PART_CUTTING) * PART_CUTTING) / 2;

	if (cut > 0)
		cut_sort_op(dual, cut, rot_fct);
	else
		cut_sort_op(dual, 1, rot_fct);
	infix_sort_rev(dual, dual->tree);
}

void	cut_sort_ra(t_dualstack *dual)
{
	cut_sort(dual, ra);
}

void	cut_sort_rra(t_dualstack *dual)
{
	cut_sort(dual, rra);
}
