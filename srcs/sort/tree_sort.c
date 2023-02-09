/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/09 11:57:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_nextbefore(t_dualstack *dual, const size_t index, const size_t next_index)
{
	const size_t	half_size = ft_lstsize(dual->a);

	return (get_abs(next_index - half_size) > get_abs(index - half_size) + 1);
}

/////////////////////////////////////////

static void	put_top_a(t_dualstack *dual, const size_t index)
{
	const int		nb = get_nb_from_index(dual->a, index);
	const size_t	half_size = ft_lstsize(dual->a) / 2;
	t_stack			*curr_stack;

	curr_stack = (dual->a->content);
	while (curr_stack->nb != nb)
	{
		if (index <= half_size)
			ra(dual);
		else
			rra(dual);
//		print_dualstack(dual);
		curr_stack = (dual->a->content);
	}
}

static void	push_index_to_b(t_dualstack *dual, const size_t index)
{
	put_top_a(dual, index);
	pb(dual);
	//print_dualstack(dual);
}

static void	stack_op(t_dualstack *dual, const int content)
{
	bool			is_nextbefore_val;
	const ssize_t	index = get_index_from_nb(dual->a, content);
	const ssize_t	next_index = get_next_index_from_nb(dual->a, content);
	size_t			curr_index;

	is_nextbefore_val = false;
	if (next_index != -1)
		is_nextbefore_val = is_nextbefore(dual, index, next_index);
	if (is_nextbefore_val == true)
		push_index_to_b(dual, next_index);
	curr_index = get_index_from_nb(dual->a, content);
	push_index_to_b(dual, curr_index);
	if (is_nextbefore_val == true)
		sb(dual);
}

static void	infix_sort(t_dualstack *dual, t_tree *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			infix_sort(dual, root->left);
		if (isin_stack(dual->a, root->content) == true)
			stack_op(dual, root->content);
		if (root->right != NULL)
			infix_sort(dual, root->right);
	}
}

// INFIX_SORT_REV

static void	put_top_b(t_dualstack *dual, const size_t index)
{
	const int		nb = get_nb_from_index(dual->b, index);
	const size_t	half_size = ft_lstsize(dual->b) / 2;
	t_stack			*curr_stack;

	curr_stack = (dual->b->content);
	while (curr_stack->nb != nb)
	{
		if (index <= half_size)
			rb(dual);
		else
			rrb(dual);
//		print_dualstack(dual);
		curr_stack = (dual->b->content);
	}
}

static void	push_index_to_a(t_dualstack *dual, const size_t index)
{
	put_top_b(dual, index);
	pa(dual);
	//print_dualstack(dual);
}

static void	stack_op_rev(t_dualstack *dual, const int content)
{
	bool			is_nextbefore_val;
	const ssize_t	index = get_index_from_nb(dual->b, content);
	const ssize_t	prev_index = get_prev_index_from_nb(dual->b, content);
	size_t			curr_index;

	is_nextbefore_val = false;
	if (prev_index != -1)
		is_nextbefore_val = is_nextbefore(dual, prev_index, index);
	if (is_nextbefore_val == true)
		push_index_to_a(dual, prev_index);
	curr_index = get_index_from_nb(dual->b, content);
	push_index_to_a(dual, curr_index);
	if (is_nextbefore_val == true)
		sa(dual);
}

static void	infix_sort_rev(t_dualstack *dual, t_tree *root)
{
	if (root != NULL)
	{
		if (root->right != NULL)
			infix_sort_rev(dual, root->right);
		if (isin_stack(dual->b, root->content) == true)
			stack_op_rev(dual, root->content);
		if (root->left != NULL)
			infix_sort_rev(dual, root->left);
	}
}

/////// TREE_SORT

static void	tree_sort_rec(t_dualstack *dual, t_tree *root, const size_t size)
{
	const size_t	old_size_b = ft_lstsize(dual->b);
	size_t			pushed_count;
	size_t			i;

	if (size > 0)
	{
		i = 0;
		while (i < size / 2 && is_stack_sorted(dual->a) == false)
		{
			pb(dual);
			++i;
		}
		infix_sort(dual, root);
		pushed_count = ft_lstsize(dual->b) - old_size_b;
		i = 0;
		while (is_stack_rev_sorted(dual->b) == false && i < pushed_count) // && i < size / 2 + size / 4)
		{
			pa(dual);
			++i;
		}
		tree_sort_rec(dual, root, size / 2);
		infix_sort_rev(dual, root);
	}
}

void	tree_sort(t_dualstack *dual, t_tree *root)
{
	const size_t	size = ft_lstsize(dual->a);

	tree_sort_rec(dual, root, size);
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
	// infix_sort(dual, root);
	// while (dual->b != NULL)
	// 	pa(dual);
	fact_instructions(&(dual->instructions));
}
