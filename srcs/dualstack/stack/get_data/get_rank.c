/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:54:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/27 23:58:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_nb_from_rank(t_list *stack, const size_t rank)
{
	while (stack != NULL && get_rank(stack) != rank)
		stack = stack->next;
	if (stack == NULL)
		return (INVALID_NB);
	return (get_nb(stack));
}

size_t	get_rank_from_index(t_list *stack, size_t index)
{
	size_t	i;

	i = 0;
	while (stack != NULL && i < index)
	{
		++i;
		stack = stack->next;
	}
	if (stack == NULL)
		return (0);
	return (get_rank(stack));
}

ssize_t	get_rank_from_nb(t_list *stack, const int nb)
{
	while (stack != NULL && get_nb(stack) != nb)
		stack = stack->next;
	if (stack == NULL)
		return (-1);
	return (get_rank(stack));
}
