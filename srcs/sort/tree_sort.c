/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/10 15:07:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	tree_sort_rec(t_dualstack *dual, t_tree *root, const size_t size)
{
	const size_t	old_size_b = ft_lstsize(dual->b);
	size_t			pushed_count;
	size_t			i;

	if (size > 0)
	{
		infix_sort_rev(dual, root);
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
