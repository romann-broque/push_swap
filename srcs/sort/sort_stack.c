/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 03:31:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list *stack_a)
{
	t_dualstack	dual;

	dual.a = stack_a;
	dual.b = NULL;
	dual.instructions = NULL;
	sort_dualstack(&dual);
	ft_lstclear(&(dual.a), NULL);
	ft_lstclear(&(dual.b), NULL);
	ft_lstclear(&(dual.instructions), NULL);
}
