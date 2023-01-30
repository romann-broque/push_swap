/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/30 16:09:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	last(t_list *stack)
{
	return (*((int *)(ft_lstlast(stack)->content)));
}

static int	top(t_list *stack)
{
	return (*((int *)stack->content));
}

#include <unistd.h>

void	sort_dualstack(t_dualstack *dual)
{
	while (is_stack_sorted(dual->a) == false || ft_lstsize(dual->b) > 0)
	{
		if (last(dual->a) > top(dual->a))
			rra(dual);
		else if (dual->a != NULL && dual->a->next && top(dual->a) > top(dual->a->next))
			sa(dual);
		else if (dual->b != NULL && dual->b->next && top(dual->b) < top(dual->b->next))
			sb(dual);
		else
		{
			if (dual->b == NULL || top(dual->a) < top(dual->b))
				pb(dual);
			else
				pa(dual);
		}
		print_dualstack(dual);
		sleep(1); // remove after tests
	}
	while (is_stack_valid(dual->a) == false)
	{
		rra(dual);
		printf("rotate\n");
		print_dualstack(dual);
		sleep(1); // remove after tests
	}
}
