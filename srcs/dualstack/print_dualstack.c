/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dualstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:49:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:58:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_dualstack(t_dualstack *dual)
{
	t_list	*a_cpy;
	t_list	*b_cpy;

	a_cpy = dual->a;
	b_cpy = dual->b;
	while (a_cpy || b_cpy)
	{
		if (a_cpy != NULL)
		{
			ft_printf("%d", *(int *)(a_cpy->content));
			a_cpy = a_cpy->next;
		}
		ft_printf("      ");
		if (b_cpy != NULL)
		{
			ft_printf("%d", *(int *)(b_cpy->content));
			b_cpy = b_cpy->next;
		}
		ft_printf("\n");
	}
	ft_printf("a      b\n");
	ft_printf("--------\n");
}
