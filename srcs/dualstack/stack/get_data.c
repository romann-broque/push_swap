/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:19:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 16:48:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_rank_from_nb(t_list *stack, const int nb)
{
	while (((t_stack *)(stack->content))->nb != nb)
		stack = stack->next;
	return (((t_stack *)(stack->content))->rank);
}

static int	get_nb_from_rank(t_list *stack, const size_t rank)
{
	while (((t_stack *)(stack->content))->rank != rank)
		stack = stack->next;
	return (((t_stack *)(stack->content))->nb);
}

size_t	get_index_from_nb(t_list *stack, const int nb)
{
	size_t	index;

	index = 0;
	while (stack != NULL && ((t_stack *)(stack->content))->nb != nb)
	{
		++index;
		stack = stack->next;
	}
	return (index);
}

int	get_nb_from_index(t_list *stack, const size_t index)
{
	size_t	i;

	i = 0;
	while (stack != NULL && i < index)
	{
		++i;
		stack = stack->next;
	}
	return (((t_stack *)(stack->content))->nb);
}

size_t	get_next_index_from_nb(t_list *stack, const int nb)
{
	size_t	rank;
	size_t	next_nb;

	if (stack == NULL || stack->next == NULL)
		return (0);
	rank = get_rank_from_nb(stack, nb);
	next_nb = get_nb_from_rank(stack, rank + 1);
	return (get_index_from_nb(stack, next_nb));
}
