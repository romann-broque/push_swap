/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 16:07:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get_data_from_other_data //

static int	get_nb_from_index(t_list *stack, const size_t index)
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

static size_t	get_index_from_nb(t_list *stack, const int nb)
{
	size_t	index;

	index = 0;
	while (((t_stack *)(stack->content))->nb != nb)
	{
		++index;
		stack = stack->next;
	}
	return (index);
}

static size_t	get_next_index_from_nb(t_list *stack, const int nb)
{
	size_t	rank;
	size_t	next_nb;

	if (stack == NULL || stack->next == NULL)
		return (0);
	rank = get_rank_from_nb(stack, nb);
	next_nb = get_nb_from_rank(stack, rank + 1);
	return (get_index_from_nb(stack, next_nb));
}

//////////////////

static void	push_index_to_b(t_dualstack *dual, const size_t index)
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
		print_dualstack(dual);
		curr_stack = (dual->a->content);
	}
	pb(dual);
	print_dualstack(dual);
}

static void	stack_op(t_dualstack *dual, const int content)
{
	const size_t	index = get_nb_index(dual->a, content);
	const size_t	next_index = get_next_index_from_nb(dual->a, content);

	printf("nb -> %d / index -> %zu / next_index -> %zu\n", content, index, next_index);
	print_dualstack(dual);
	push_index_to_b(dual, index);
}

static void	infix_sort(t_dualstack *dual, t_tree *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			infix_sort(dual, root->left);
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
	print_dualstack(dual);
	fact_instructions(dual->instructions);
}
