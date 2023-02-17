/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:00:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/17 11:32:39 by rbroque          ###   ########.fr       */
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

size_t	get_first_index_part(t_list *stack, const size_t part)
{
	size_t	index;

	index = 0;
	while (stack != NULL && ((t_stack *)(stack->content))->rank > part)
	{
		++index;
		stack = stack->next;
	}
	return (index);
}

size_t	get_last_index_part(t_list *stack, const size_t part)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (stack != NULL)
	{
		if (((t_stack *)(stack->content))->rank < part)
			index = i;
		++i;
		stack = stack->next;
	}
	return (index);
}

void	put_lower_top_a(t_dualstack *dual, const size_t curr_part)
{
	const size_t	size = ft_lstsize(dual->a);
	const size_t	index1 = get_first_index_part(dual->a, curr_part);
	const size_t	index2 = get_last_index_part(dual->a, curr_part);

	if (index1 <= size - index2)
	{
		if (index1 < size / 2)
			ra(dual);
		else
			rra(dual);
	}
	else
		rra(dual);
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
			put_lower_top_a(dual, ((part) * max_rank) / part_count);
	}
	infix_sort_rev(dual, dual->tree);
}
