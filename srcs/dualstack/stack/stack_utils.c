/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:50:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/27 23:39:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb(t_list *elem_stack)
{
	return (((t_stack *)(elem_stack->content))->nb);
}

size_t	get_rank(t_list *elem_stack)
{
	return (((t_stack *)(elem_stack->content))->rank);
}

int	get_disp(const t_stack *element1, const t_stack *element2)
{
	if (element1 != NULL && element2 != NULL)
		return (element2->rank - element1->rank);
	return (0);
}

bool	isin_stack(t_list *stack, const int nb)
{
	return (get_index_from_nb(stack, nb) != -1);
}

float	get_average_disp(t_list *stack)
{
	const size_t	size = ft_lstsize(stack);
	size_t			sum;

	if (size == 0)
		return (0);
	sum = 0;
	while (stack != NULL)
	{
		if (stack->next != NULL)
			sum += get_abs(get_disp(stack->content, stack->next->content));
		stack = stack->next;
	}
	return ((float)(sum + 1) / (float)size);
}
