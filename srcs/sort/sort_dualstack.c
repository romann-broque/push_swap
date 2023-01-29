/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dualstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 23:35:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*last(t_list *stack)
{
	return (ft_lstlast(stack));
}

static t_list	*top(t_list *stack)
{
	return (stack);
}

void	sort_dualstack(t_dualstack *dual)
{
	while (is_stack_sorted(dual->a) == false || ft_lstsize(dual->b) > 0)
	{
		if (are_nb_sorted(last(dual->a), top(dual->b)) == true)
			pa(dual);
		else if (are_nb_sorted(last(dual->a), top(dual->a)) == true)
			rra(dual);
		else
			pb(dual);
		print_dualstack(dual);
	}
}
