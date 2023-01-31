/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dualstack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:23:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 18:24:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dualstack(t_dualstack *dual, t_stack *numbers, const size_t count)
{
	dual->a = gen_list(numbers, count);
	dual->b = NULL;
	dual->instructions = NULL;
}

void	free_dualstack(t_dualstack *dual)
{
	ft_lstclear(&(dual->a), NULL);
	ft_lstclear(&(dual->b), NULL);
	ft_lstclear(&(dual->instructions), NULL);
}
