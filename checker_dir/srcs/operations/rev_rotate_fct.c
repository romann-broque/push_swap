/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:46:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 14:46:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_fct(t_dualstack *dual)
{
	rev_rotate(&(dual->a));
}

void	rrb_fct(t_dualstack *dual)
{
	rev_rotate(&(dual->b));
}

void	rrr_fct(t_dualstack *dual)
{
	rev_rotate(&(dual->a));
	rev_rotate(&(dual->b));
}
