/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:40:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/02 18:51:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_stack(t_list *lst, const int nb)
{
	while (lst != NULL)
	{
		if (((t_stack *)(lst->content))->nb == nb)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}

static void	set_rank(t_tree *root, t_list *stack, size_t *rank)
{
	t_stack	*curr_stack;

	if (root != NULL)
	{
		curr_stack = stack->content;
		set_rank(root->left, stack, rank);
		++(*rank);
		curr_stack = find_stack(stack, root->content);
		curr_stack->rank = *rank;
		set_rank(root->right, stack, rank);
	}
}

void	set_rank_stack(t_tree *root, t_list *stack)
{
	size_t	init_rank;

	init_rank = 0;
	set_rank(root, stack, &init_rank);
}
