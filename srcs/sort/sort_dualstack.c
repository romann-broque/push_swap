/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/30 19:49:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

static void	print_wait_dual(t_dualstack *dual)
{
	print_dualstack(dual);
	//sleep(1); // remove after tests
}

static void	infix_sort(t_dualstack *dual, t_tree *root)
{
	if (root->left != NULL)
		infix_sort(dual, root->left);
	while (*((int *)(dual->a->content)) != root->content)
	{
		ra(dual);
		print_wait_dual(dual);
	}
	pb(dual);
	print_wait_dual(dual);
	if (root->right != NULL)
		infix_sort(dual, root->right);
}

static void	tree_sort(t_dualstack *dual, t_tree *root)
{
	infix_sort(dual, root);
	while (dual->b != NULL)
	{
		pa(dual);
		print_wait_dual(dual);
	}
}

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;

	tree = create_tree(dual->a);
//	display_tree(tree);
	tree_sort(dual, tree);
	//free(tree);
}
