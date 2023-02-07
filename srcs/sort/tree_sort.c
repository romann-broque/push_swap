/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/07 11:49:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_nextbefore(t_dualstack *dual, const size_t index, const size_t next_index)
{
	const size_t	half_size = ft_lstsize(dual->a);

	return (get_abs(next_index - half_size) > get_abs(index - half_size) + 1);
}

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

// static void	indicate_rra(t_dualstack *dual)
// {
// 	ft_contadd_back(&(dual->instructions), "id");
// }

static void	stack_op(t_dualstack *dual, const int content)
{
	bool			is_nextbefore_val;
	const size_t	index = get_index_from_nb(dual->a, content);
	const size_t	next_index = get_next_index_from_nb(dual->a, content);
	size_t			curr_index;
	// const size_t	rank = get_rank_from_nb(dual->a, content);

	//print_dualstack(dual);
	is_nextbefore_val = is_nextbefore(dual, index, next_index);
	if (is_nextbefore_val == true)
		push_index_to_b(dual, next_index);
	curr_index = get_index_from_nb(dual->a, content);
	push_index_to_b(dual, curr_index);
	if (is_nextbefore_val == true)
	{
		sb(dual);
		// if (dual->a != NULL && dual->a->next != NULL
		// 	&& ((t_stack *)(dual->a->content))->rank != rank + 1
		// 	&& ((t_stack *)(dual->a->next->content))->rank != rank + 1)
		// {
		// 	indicate_rra(dual);
		// 	indicate_rra(dual);
		// }
	}
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

void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
	fact_instructions(&(dual->instructions));
}
