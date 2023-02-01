/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:26:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/01 16:48:40 by rbroque          ###   ########.fr       */
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

// bool	is_stack_sorted(t_list *stack)
// {
// 	bool	is_end_reached;
// 	int		max;
// 	int		min;
// 	int		curr;

// 	is_end_reached = false;
// 	max = INT_MIN;
// 	min = INT_MAX;
// 	while (stack != NULL)
// 	{
// 		curr = *((int *)(stack->content));
// 		if (is_end_reached == false)
// 		{
// 			if (max < curr)
// 				max = curr;
// 			if (min > curr)
// 				min = curr;
// 			if (max > curr)
// 				is_end_reached = true;
// 		}
// 		if (is_end_reached == true)
// 		{
// 			if (max < curr || min < curr)
// 				return (false);
// 		}
// 		stack = stack->next;
// 	}
// 	return (true);
// }


bool	are_nb_sorted(t_list *n1, t_list *n2)
{
	return (n1 != NULL && n2 != NULL && (*((int *)n1->content) < *((int *)n2->content)));
}
