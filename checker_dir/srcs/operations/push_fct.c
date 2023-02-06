/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:45:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 14:45:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_fct(t_dualstack *dual)
{
	push(&(dual->b), &(dual->a));
}

void	pb_fct(t_dualstack *dual)
{
	push(&(dual->a), &(dual->b));
}
