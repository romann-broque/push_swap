/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:26:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/05 22:26:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	get_sign(const char **nb)
{
	int	sign;

	sign = 1;
	if (**nb == '-' || **nb == '+')
	{
		if (**nb == '-')
			sign = -1;
		++(*nb);
	}
	return (sign);
}

static bool	is_valid_int(const char *nb)
{
	long	new;
	int		sign;

	new = 0;
	sign = get_sign(&nb);
	while (ft_isdigit(*nb) != 0)
	{
		new = new * 10 + (*nb - '0');
		++nb;
	}
	new *= sign;
	return (new >= INT_MIN && new <= INT_MAX && *nb == '\0');
}

static bool	is_nb_valid(const char *nb)
{
	return (is_valid_int(nb));
}

bool	are_nb_valid(char **numbers)
{
	while (*numbers != NULL && is_nb_valid(*numbers) == true)
		++(numbers);
	return (*numbers == NULL);
}
