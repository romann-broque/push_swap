/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:05:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/30 21:35:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *stack)
{
	void	*tmp;

	while (stack != NULL)
	{
		tmp = stack->content;
		if (stack->next != NULL)
		{
			stack->content = (stack->next)->content;
			(stack->next)->content = tmp;
		}
		stack = stack->next;
	}
}

void	ra(t_dualstack *dual)
{
	ft_printf("ra\n");
	rotate(dual->a);
}

void	rb(t_dualstack *dual)
{
	ft_printf("rb\n");
	rotate(dual->b);
}

void	rr(t_dualstack *dual)
{
	ft_printf("rr\n");
	rotate(dual->a);
	rotate(dual->b);
}
