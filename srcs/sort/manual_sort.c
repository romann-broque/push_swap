/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:36:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/24 17:29:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sort_three(t_dualstack *dual)
{
	const size_t	size = ft_lstsize(dual->a);
	t_list *const	stack = dual->a;

	return (size == 3
		&& get_nb(stack) == 3
		&& get_nb(stack->next) == 2
		&& get_nb(stack->next->next) == 1);
}

void	manual_sort(t_dualstack *dual)
{
	if (is_sort_three(dual) == true)
	{
		sa(dual);
		rra(dual);
	}
	else
		rank_sort(dual);
}
