/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 18:44:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_next_rotate1(t_list *stack)
{
	const size_t	size = ft_lstsize(stack);
	int				min_disp;
	int				curr_disp;
	long			rotate;
	size_t			i;

	min_disp = INT_MAX;
	curr_disp = 0;
	rotate = 0;
	i = 0;
	while (stack != NULL)
	{
		if (stack->next != NULL)
			curr_disp = get_disp(stack->content, stack->next->content);
		if (curr_disp < 0 && get_abs(min_disp) >= get_abs(curr_disp))
		{
			min_disp = curr_disp;
			rotate = i;
		}
		++i;
		stack = stack->next;
	}
	if (rotate <= (long)(size / 2))
		return (rotate);
	return (-(rotate - (size / 2)));
}

static long	get_next_rotate2(t_list *stack, const size_t ref_rank)
{
	const size_t	size = ft_lstsize(stack);
	long			rotate;
	size_t			i;

	rotate = 0;
	i = 0;
	while (stack != NULL)
	{
		if ((long)(((t_stack *)(stack->content))->rank) - (long)ref_rank == 1)
			rotate = i;
		++i;
		stack = stack->next;
	}
	if (get_abs(rotate) <= size / 2)
		return (rotate);
	return (-(rotate - (size / 2)));
}

static void	put_mindisp_top(t_dualstack *dual, const long rotate_count)
{
	const size_t	abs_count = get_abs(rotate_count);
	void			(*rotate_fct)(t_dualstack *);
	size_t			i;

	rotate_fct = ra;
	if (rotate_count < 0)
		rotate_fct = rra;
	i = 0;
	while (i < abs_count)
	{
		rotate_fct(dual);
		++i;
	}
}

static void	rank_op(t_dualstack *dual)
{
	const long	rotate_count1 = get_next_rotate1(dual->a);
	long		rotate_count2;

	if (rotate_count1 != 0)
	{
		put_mindisp_top(dual, rotate_count1);
		pb(dual);
		rotate_count2 = get_next_rotate2(dual->a, ((t_stack *)(dual->b->content))->rank);
		put_mindisp_top(dual, rotate_count2);
		pa(dual);
	}
	else
		sa(dual);
}

void	rank_sort(t_dualstack *dual)
{
	while (is_stack_sorted(dual->a) == false)
		rank_op(dual);
	tree_sort(dual);
	put_top_a(dual, get_index_from_rank(dual->a, 1));
}
