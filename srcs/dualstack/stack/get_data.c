/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:19:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/10 15:23:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	get_rank_from_nb(t_list *stack, const int nb)
{
	while (stack != NULL && ((t_stack *)(stack->content))->nb != nb)
		stack = stack->next;
	if (stack == NULL)
		return (-1);
	return (((t_stack *)(stack->content))->rank);
}

static long	get_nb_from_rank(t_list *stack, const size_t rank)
{
	while (stack != NULL && ((t_stack *)(stack->content))->rank != rank)
		stack = stack->next;
	if (stack == NULL)
		return (INVALID_NB);
	return (((t_stack *)(stack->content))->nb);
}

ssize_t	get_index_from_nb(t_list *stack, const int nb)
{
	ssize_t	index;

	index = 0;
	while (stack != NULL && ((t_stack *)(stack->content))->nb != nb)
	{
		++index;
		stack = stack->next;
	}
	if (stack == NULL)
		return (-1);
	return (index);
}

long	get_nb_from_index(t_list *stack, const size_t index)
{
	size_t	i;

	i = 0;
	while (stack != NULL && i < index)
	{
		++i;
		stack = stack->next;
	}
	if (stack == NULL)
		return (INVALID_NB);
	return (((t_stack *)(stack->content))->nb);
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

ssize_t	get_next_index_from_index(t_list *stack, const size_t index)
{
	const long	nb = get_nb_from_index(stack, index + 1);

	if (nb == INVALID_NB)
		return (0);
	return (get_index_from_nb(stack, nb));
}
