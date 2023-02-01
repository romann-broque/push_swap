/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/01 14:58:35 by rbroque          ###   ########.fr       */
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

static void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
	fact_instructions(dual->instructions);
}

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;

	tree = create_tree(dual->a);
	set_index_stack(tree, dual->a);

	tree_sort(dual, tree);
	print_instructions(dual->instructions);
	clear_tree(tree);
}
