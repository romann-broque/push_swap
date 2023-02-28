/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:37:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 17:08:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	taylor_approx(double x)
{
	size_t	k;
	double	t;
	double	s;
	double	z;

	x -= 1;
	t = 0.0;
	s = 1.0;
	z = x;
	k = 1;
	while (k <= TAYLOR_ITERATIONS)
	{
		t += z * s / k;
		z *= x;
		s = -s;
		++k;
	}
	return (t);
}

double	ft_log(double x)
{
	int	power_adjust;

	if (x <= 0)
		return (0.0 / 0.0);
	power_adjust = 0;
	while (x > 1.0)
	{
		x /= EULER_CONST;
		power_adjust++;
	}
	while (x < .25)
	{
		x *= EULER_CONST;
		power_adjust--;
	}
	return (taylor_approx(x) + power_adjust);
}
