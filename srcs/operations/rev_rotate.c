/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:56:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 23:09:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*curr;
	t_list	*last;

	curr = *stack;
	last = ft_lstlast(*stack);
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->next->next == NULL)
			curr->next = NULL;
		curr = curr->next;
	}
	if (last != *stack)
		last->next = *stack;
	*stack = last;
}

void	rra(t_dualstack *dual)
{
	rev_rotate(&(dual->a));
}

void	rrb(t_dualstack *dual)
{
	rev_rotate(&(dual->b));
}

void	rrr(t_dualstack *dual)
{
	rra(dual);
	rrb(dual);
}
