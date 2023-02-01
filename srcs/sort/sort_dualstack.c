/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/01 18:20:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_op(t_dualstack *dual, int content)
{
	const int	index = get_nb_index(dual->a, content);
	const int	half_size = ft_lstsize(dual->a) / 2;
	t_stack		*curr_stack;

	curr_stack = (dual->a->content);
	while (curr_stack->nb != content)
	{
	//	if (curr_stack->nb != content && dual->a->next->content != content && )
		if (index <= half_size)
			ra(dual);
		else
			rra(dual);
		//print_dualstack(dual);
		curr_stack = (dual->a->content);
	}
	pb(dual);
	//print_dualstack(dual);
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
	fact_instructions(dual->instructions);
}

/////////////////
/// RANK_SORT ///
////////////////

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
		if (curr_disp < 0 && get_abs(min_disp) > get_abs(curr_disp))
		{
			min_disp = curr_disp;
			rotate = i;
		}
		++i;
		stack = stack->next;
	}
	if (rotate <= (long)(size / 2))
		return (rotate);
	return (-(rotate - (size / 2 + 1)));
}

long	get_next_rotate2(t_list *stack, const size_t ref_index)
{
	const size_t	size = ft_lstsize(stack);
	long			rotate;
	size_t			i;

	rotate = 0;
	i = 0;
	while (stack != NULL)
	{
		if ((long)(((t_stack *)(stack->content))->index) - (long)ref_index == 1)
			rotate = i;
		++i;
		stack = stack->next;
	}
	if (get_abs(rotate) <= size / 2)
		return (rotate);
	return (-(rotate - (size / 2 + 1)));
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
		//print_dualstack(dual);
		rotate_fct(dual);
		++i;
	}
	//print_dualstack(dual);
}

static void	rank_op(t_dualstack *dual)
{
	const long	rotate_count1 = get_next_rotate1(dual->a);
	long		rotate_count2;

	put_mindisp_top(dual, rotate_count1);
	if (get_abs(rotate_count1) > 0)
	{
		pb(dual);
		rotate_count2 = get_next_rotate2(dual->a, ((t_stack *)(dual->b->content))->index);
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
	//print_dualstack(dual);
	//fact_instructions(dual->instructions);
}

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;

	tree = create_tree(dual->a);
	set_index_stack(tree, dual->a);
	//rank_sort(dual);
	tree_sort(dual, tree);
	//printf("av_disp = %f\n", get_average_disp(dual->a));
	print_instructions(dual->instructions);
	clear_tree(tree);
}
