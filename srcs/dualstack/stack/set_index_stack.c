/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:40:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 22:40:26 by rbroque          ###   ########.fr       */
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

static void	set_index(t_tree *root, t_list *stack, size_t *index)
{
	t_stack	*curr_stack;

	if (root != NULL)
	{
		curr_stack = stack->content;
		set_index(root->left, stack, index);
		++(*index);
		curr_stack = find_stack(stack, root->content);
		curr_stack->index = *index;
		set_index(root->right, stack, index);
	}
}

void	set_index_stack(t_tree *root, t_list *stack)
{
	size_t	init_index;

	init_index = 0;
	set_index(root, stack, &init_index);
}
