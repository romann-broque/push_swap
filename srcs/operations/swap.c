/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/30 21:36:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	void	*tmp;

	if (stack != NULL && stack->next != NULL)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

void	sa(t_dualstack	*dual)
{
	ft_printf("sa\n");
	swap(dual->a);
}

void	sb(t_dualstack	*dual)
{
	ft_printf("sb\n");
	swap(dual->b);
}

void	ss(t_dualstack	*dual)
{
	ft_printf("ss\n");
	swap(dual->a);
	swap(dual->b);
}
