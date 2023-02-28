/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:46:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 14:46:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_fct(t_dualstack *dual)
{
	rotate(dual->a);
}

void	rb_fct(t_dualstack *dual)
{
	rotate(dual->b);
}

void	rr_fct(t_dualstack *dual)
{
	rotate(dual->a);
	rotate(dual->b);
}
