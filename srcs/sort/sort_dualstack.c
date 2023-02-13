/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/13 15:22:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_round(const float f_nb)
{
	return (((size_t)(f_nb * 10 + 0.5)) / 10.);
}

void	sort_dualstack(t_dualstack *dual)
{
	const size_t	disp = ft_round(get_average_disp(dual->a));

	(void)disp;
	// if (disp / PART_CUTTING > 0)
	// 	pre_sort(dual, disp / PART_CUTTING);
	// else if (PART_CUTTING > 0)
		pre_sort(dual, 5);
	// else
	// 	tree_sort(dual, dual->tree);
	fact_instructions(&(dual->instructions));
	print_instructions(dual->instructions);
}
