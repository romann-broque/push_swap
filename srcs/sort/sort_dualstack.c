/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 04:54:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

static int	get_nb_index(t_list *stack, const int nb)
{
	int	index;

	index = 0;
	while (stack != NULL && *((int *)(stack->content)) != nb)
	{
		stack = stack->next;
		++index;
	}
	return (index);
}

static void	infix_sort(t_dualstack *dual, t_tree *root)
{
	const int	half_size = ft_lstsize(dual->a) / 2;
	const int	index = get_nb_index(dual->a, root->content);

	if (root->left != NULL)
		infix_sort(dual, root->left);
	while (*((int *)(dual->a->content)) != root->content)
	{
		if (index < half_size)
			ra(dual);
		else
			rra(dual);
	}
	pb(dual);
	if (root->right != NULL)
		infix_sort(dual, root->right);
}

static void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
		pa(dual);
}

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;

	tree = create_tree(dual->a);
	//	display_tree(tree);
	tree_sort(dual, tree);
	fact_instructions(dual->instructions);
	print_instructions(dual->instructions);
	//clear_tree(tree);
}
