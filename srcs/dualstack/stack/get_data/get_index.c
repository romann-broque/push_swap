/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:54:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:23:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	get_index_from_nb(t_list *stack, const int nb)
{
	ssize_t	index;

	index = 0;
	while (stack != NULL && get_nb(stack) != nb)
	{
		++index;
		stack = stack->next;
	}
	if (stack == NULL)
		return (-1);
	return (index);
}

ssize_t	get_prev_index_from_nb(t_list *stack, const int nb)
{
	ssize_t	rank;
	long	next_nb;

	if (stack == NULL || stack->next == NULL)
		return (0);
	rank = get_rank_from_nb(stack, nb);
	if (rank > 0)
		next_nb = get_nb_from_rank(stack, rank - 1);
	else
		return (-1);
	return (get_index_from_nb(stack, next_nb));
}

ssize_t	get_next_index_from_index(
	t_list *stack_src,
	t_list *stack_dest,
	const size_t index)
{
	const size_t	rank = get_rank_from_index(stack_src, index);
	const long		nb = get_nb_from_rank(stack_dest, rank + 1);

	if (nb == INVALID_NB)
		return (0);
	return (get_index_from_nb(stack_dest, nb));
}

ssize_t	get_next_index_from_nb(t_list *stack, const int nb)
{
	ssize_t	rank;
	long	next_nb;

	if (stack == NULL || stack->next == NULL)
		return (0);
	rank = get_rank_from_nb(stack, nb);
	next_nb = get_nb_from_rank(stack, rank + 1);
	if (next_nb == INVALID_NB)
		return (-1);
	return (get_index_from_nb(stack, next_nb));
}

ssize_t	get_index_from_rank(t_list *stack, const size_t rank)
{
	ssize_t	index;

	index = 0;
	while (stack != NULL && get_rank(stack) != rank)
	{
		++index;
		stack = stack->next;
	}
	if (stack == NULL)
		return (-1);
	return (index);
}
