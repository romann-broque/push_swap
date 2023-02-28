/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:45:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 14:48:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_fct(t_dualstack *dual)
{
	swap(dual->a);
}

void	sb_fct(t_dualstack *dual)
{
	swap(dual->b);
}

void	ss_fct(t_dualstack *dual)
{
	swap(dual->a);
	swap(dual->b);
}
