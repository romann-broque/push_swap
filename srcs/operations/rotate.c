/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:05:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 18:18:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *stack)
{
	void	*first_cont;

	if (stack != NULL)
		first_cont = stack->content;
	while (stack != NULL)
	{
		if (stack->next != NULL)
			stack->content = stack->next->content;
		else
			stack->content = first_cont;
		stack = stack->next;
	}
}

void	ra(t_dualstack	*dual)
{
	rotate(dual->a);
}

void	rb(t_dualstack	*dual)
{
	rotate(dual->b);
}
