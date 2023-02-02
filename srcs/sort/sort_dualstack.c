/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/02 18:51:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dualstack(t_dualstack *dual)
{
	t_tree	*tree;

	tree = create_tree(dual->a);
	set_rank_stack(tree, dual->a);
	//rank_sort(dual);
	tree_sort(dual, tree);
	//printf("av_disp = %f\n", get_average_disp(dual->a));
	print_instructions(dual->instructions);
	clear_tree(tree);
}
