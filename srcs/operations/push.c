/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:14:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:37:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*new;
	t_list	*root;

	root = *stack_src;
	if (stack_src != NULL)
	{
		new = ft_lstnew((*stack_src)->content);
		if (new != NULL)
		{
			ft_lstadd_front(stack_dest, new);
			*stack_src = (*stack_src)->next;
			free(root);
		}
	}
}

void	pa(t_dualstack *dual)
{
	push(&(dual->b), &(dual->a));
}

void	pb(t_dualstack *dual)
{
	push(&(dual->a), &(dual->b));
}
