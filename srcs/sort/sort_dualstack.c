/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 23:26:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dualstack(t_dualstack *dual)
{
	const size_t		size = ft_lstsize(dual->a);
	static t_sort_fct	sort_fct_array[SORT_FCT_COUNT + 1] = {
	{.sort_fct = pre_sort_ra, .max_size = SIZE_MAX},
	{.sort_fct = pre_sort_rra, .max_size = SIZE_MAX},
	{.sort_fct = tree_sort, .max_size = 100},
	{.sort_fct = rank_sort, .max_size = PART_CUTTING},
	{.sort_fct = NULL, .max_size = 0},
	};

	if (size > 0)
	{
		apply_best_sort(dual, sort_fct_array);
		fact_instructions(&(dual->instructions));
		print_instructions(dual->instructions);
	}
}
