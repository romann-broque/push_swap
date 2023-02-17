/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/17 23:04:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dualstack(t_dualstack *dual)
{
	const size_t	size = ft_lstsize(dual->a);
	const size_t	cut = (ft_log((double)size / (double)PART_CUTTING) * PART_CUTTING) / 2;

	if (size > 0)
	{
		if (cut > 0)
			pre_sort(dual, cut);
		else
			tree_sort(dual, dual->tree);
		fact_instructions(&(dual->instructions));
		print_instructions(dual->instructions);
	}
}
