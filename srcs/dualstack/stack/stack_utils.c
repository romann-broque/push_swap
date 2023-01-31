/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:50:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 22:41:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb_index(t_list *stack, const int nb)
{
	int	index;

	index = 0;
	while (stack != NULL && *((int *)(stack->content)) != nb)
	{
		stack = stack->next;
		++index;
	}
	return (index);
}
