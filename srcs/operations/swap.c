/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 01:31:40 by rbroque          ###   ########.fr       */
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
	swap(dual->a);
	ft_contadd_back(&(dual->instructions), "sa");
}

void	sb(t_dualstack	*dual)
{
	swap(dual->b);
	ft_contadd_back(&(dual->instructions), "sb");
}

void	ss(t_dualstack	*dual)
{
	swap(dual->a);
	swap(dual->b);
	ft_contadd_back(&(dual->instructions), "ss");
}
