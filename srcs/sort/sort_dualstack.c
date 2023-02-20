/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 21:17:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dualstack(t_dualstack *dual)
{
	const size_t	size = ft_lstsize(dual->a);
	const size_t	cut = (ft_log(size / PART_CUTTING) * PART_CUTTING) / 2;

	if (size > 0)
	{
		if (cut > 0)
			pre_sort(dual, cut);
		else if (size >= PART_CUTTING)
			pre_sort(dual, 1);
		else
			apply_best_sort(dual, tree_sort, rank_sort);
		fact_instructions(&(dual->instructions));
		print_instructions(dual->instructions);
	}
}
