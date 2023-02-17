/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/17 17:06:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_valid(t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL && get_disp(stack->content, stack->next->content) != 1)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_stack_sorted(t_list *stack)
{
	const size_t	size = ft_lstsize(stack);
	int				curr_disp;

	while (stack != NULL)
	{
		if (stack->next != NULL)
		{
			curr_disp = get_disp((t_stack *)(stack->content), (t_stack *)(stack->next->content));
			if (curr_disp != 1)
			{
				if (curr_disp != (int)(-(size - 1)))
					return (false);
			}
		}
		stack = stack->next;
	}
	return (true);
}

bool	is_stack_rev_sorted(t_list *stack)
{
	const size_t	size = ft_lstsize(stack);
	int				curr_disp;

	while (stack != NULL)
	{
		if (stack->next != NULL)
		{
			curr_disp = get_disp((t_stack *)(stack->content), (t_stack *)(stack->next->content));
			if (curr_disp != -1)
			{
				if (curr_disp != (int)(size - 1))
					return (false);
			}
		}
		stack = stack->next;
	}
	return (true);
}
