/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:29:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:53:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

// SORT //

// is_sorted.c

bool	is_stack_valid(t_list *stack);
bool	is_stack_sorted(t_list *stack);
bool	is_stack_rev_sorted(t_list *stack);

// cut_sort.c

void	cut_sort_ra(t_dualstack *dual);
void	cut_sort_rra(t_dualstack *dual);

// sort_dualstack.c

void	sort_dualstack(t_dualstack *dual);

// tree_sort.c

void	tree_sort(t_dualstack *dual);

// rank_sort.c

void	rank_sort(t_dualstack *dual);

// manual_sort.c

void	manual_sort(t_dualstack *dual);

// apply_best_sort.c

void	apply_best_sort(
			t_dualstack *dual,
			t_sort_fct sort_fct_array[SORT_FCT_COUNT + 1]);

// SORT_OPERATIONS

// stack_op.c

void	stack_op(t_dualstack *dual, const int content);
void	stack_op_rev(t_dualstack *dual, const int content);

// push_to_stack.c

void	put_top_a(t_dualstack *dual, const size_t index);
void	put_top_b(t_dualstack *dual, const size_t index);
void	push_index_to_a(t_dualstack *dual, const size_t index);
void	push_index_to_b(t_dualstack *dual, const size_t index);

#endif
