/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dualstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:49:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/02 18:47:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_list *stack)
{
	t_stack	*curr_stack;

	while (stack != NULL)
	{
		curr_stack = stack->content;
		printf("%d (%zu)\n", curr_stack->nb, curr_stack->rank);
		stack = stack->next;
	}
}

void	print_dualstack(t_dualstack *dual)
{
	print_stack(dual->a);
	printf("a\n");
	printf("<->\n");
	print_stack(dual->b);
	printf("b\n");
	printf("-------------------------\n");
}
