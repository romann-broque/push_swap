/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:14:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/21 15:31:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_min_list(t_list **l1, t_list *l2)
{
	const size_t	size1 = ft_lstsize(*l1);
	const size_t	size2 = ft_lstsize(l2);

	if (size1 < size2 && *l1 != NULL)
		return (*l1);
	ft_lstclear(l1, NULL);
	return (dup_list(l2));
}

void	apply_best_sort(t_dualstack *dual, t_sort_fct sort_fct_array[SORT_FCT_COUNT + 1])
{
	const size_t	size = ft_lstsize(dual->a);
	t_list			*min_instructions;
	t_dualstack		dual_cpy;
	size_t			i;

	min_instructions = NULL;
	i = 0;
	while (sort_fct_array[i].sort_fct != NULL)
	{
		if (size < sort_fct_array[i].max_size)
		{
			cpy_dualstack(&dual_cpy, dual);
			sort_fct_array[i].sort_fct(&dual_cpy);
			fact_instructions(&(dual_cpy.instructions));
			min_instructions = get_min_list(&min_instructions, dual_cpy.instructions);
			free_dualstack(&dual_cpy);
		}
		++i;
	}
	dual->instructions = dup_list(min_instructions);
	ft_lstclear(&min_instructions, NULL);
}
