/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/30 19:44:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list *stack_a)
{
	t_dualstack	dual;

	dual.a = stack_a;
	dual.b = NULL;
	sort_dualstack(&dual);
}
