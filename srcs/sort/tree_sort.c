/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 23:59:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	tree_sort_rec(t_dualstack *dual, t_tree *root, const size_t size)
{
	if (size > 0)
	{
		infix_sort(dual, root);
		while (dual->b != NULL)
			pa(dual);
		tree_sort_rec(dual, root, size / 2);
	}
}

void	tree_sort(t_dualstack *dual)
{
	const size_t	size = ft_lstsize(dual->a);
	t_tree *const	root = dual->tree;

	if (is_stack_sorted(dual->a) == false)
		tree_sort_rec(dual, root, size);
	else
		put_top_a(dual, get_index_from_rank(dual->a, 1));
}
