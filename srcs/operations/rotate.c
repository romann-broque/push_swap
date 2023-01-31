/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:05:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 01:31:04 by rbroque          ###   ########.fr       */
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
	rotate(dual->a);
	ft_contadd_back(&(dual->instructions), "ra");
}

void	rb(t_dualstack *dual)
{
	rotate(dual->b);
	ft_contadd_back(&(dual->instructions), "rb");
}

void	rr(t_dualstack *dual)
{
	rotate(dual->a);
	rotate(dual->b);
	ft_contadd_back(&(dual->instructions), "rr");
}
