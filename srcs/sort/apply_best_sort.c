/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:14:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/20 21:17:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_best_instructions(t_dualstack *dual, t_list *inst1, t_list *inst2)
{
	const size_t	size1 = ft_lstsize(inst1);
	const size_t	size2 = ft_lstsize(inst2);

	if (size1 < size2)
		dual->instructions = dup_list(inst1);
	else
		dual->instructions = dup_list(inst2);
}

void	apply_best_sort(t_dualstack *dual, void (*sort1)(t_dualstack *), void (*sort2)(t_dualstack *))
{
	t_dualstack	dual_cpy1;
	t_dualstack	dual_cpy2;

	cpy_dualstack(&dual_cpy1, dual);
	cpy_dualstack(&dual_cpy2, dual);
	sort1(&dual_cpy1);
	sort2(&dual_cpy2);
	fact_instructions(&(dual_cpy1.instructions));
	fact_instructions(&(dual_cpy2.instructions));
	assign_best_instructions(dual, dual_cpy1.instructions, dual_cpy2.instructions);
	free_dualstack(&dual_cpy1);
	free_dualstack(&dual_cpy2);
}
