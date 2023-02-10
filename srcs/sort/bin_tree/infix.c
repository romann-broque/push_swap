/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:59:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/10 15:00:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	infix_sort(t_dualstack *dual, t_tree *root)
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

void	infix_sort_rev(t_dualstack *dual, t_tree *root)
{
	if (root != NULL)
	{
		if (root->right != NULL)
			infix_sort_rev(dual, root->right);
		if (isin_stack(dual->b, root->content) == true)
			stack_op_rev(dual, root->content);
		if (root->left != NULL)
			infix_sort_rev(dual, root->left);
	}
}
