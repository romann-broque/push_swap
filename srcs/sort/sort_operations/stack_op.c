/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:03:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:03:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_nextbefore(
	t_list *stack,
	const size_t index,
	const size_t next_index)
{
	const size_t	half_size = ft_lstsize(stack);

	return (get_abs(next_index - half_size) > get_abs(index - half_size) + 1);
}

void	stack_op(t_dualstack *dual, const int content)
{
	const ssize_t	index = get_index_from_nb(dual->a, content);
	const ssize_t	next_index = get_next_index_from_nb(dual->a, content);
	size_t			curr_index;
	bool			is_nextbefore_val;

	is_nextbefore_val = false;
	if (next_index >= 0)
		is_nextbefore_val = is_nextbefore(dual->a, index, next_index);
	if (is_nextbefore_val == true)
		push_index_to_b(dual, next_index);
	curr_index = get_index_from_nb(dual->a, content);
	push_index_to_b(dual, curr_index);
	if (is_nextbefore_val == true)
		sb(dual);
}

void	stack_op_rev(t_dualstack *dual, const int content)
{
	const ssize_t	index = get_index_from_nb(dual->b, content);
	const ssize_t	prev_index = get_prev_index_from_nb(dual->b, content);
	size_t			curr_index;
	bool			is_nextbefore_val;

	is_nextbefore_val = false;
	if (prev_index >= 0)
		is_nextbefore_val = is_nextbefore(dual->b, prev_index, index);
	if (is_nextbefore_val == true)
		push_index_to_a(dual, prev_index);
	curr_index = get_index_from_nb(dual->b, content);
	push_index_to_a(dual, curr_index);
	if (is_nextbefore_val == true)
		sa(dual);
}
