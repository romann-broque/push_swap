/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_dualstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:15:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 21:19:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*dup_stack(t_list *stack)
{
	return (dup_list(stack));
}

static t_tree	*dup_tree(t_tree *root)
{
	t_tree	*new;

	new = NULL;
	if (root != NULL)
	{
		new = create_root(root->content);
		new->left = dup_tree(root->left);
		new->right = dup_tree(root->right);
	}
	return (new);
}

void	cpy_dualstack(t_dualstack *dest, t_dualstack *src)
{
	dest->a = dup_stack(src->a);
	dest->b = dup_stack(src->b);
	dest->instructions = dup_list(src->instructions);
	dest->tree = dup_tree(src->tree);
}
