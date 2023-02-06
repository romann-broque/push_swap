/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:26:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 18:27:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static bool	is_duplicated(char **numbers)
{
	size_t	i;
	size_t	j;
	int		curr_nb;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = i + 1;
		curr_nb = ft_atoi(numbers[i]);
		while (numbers[j] != NULL)
		{
			if (curr_nb == ft_atoi(numbers[j]))
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

bool	are_nb_valid(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i] != NULL && is_nb_valid(numbers[i]) == true)
		++i;
	return (numbers[i] == NULL && is_duplicated(numbers) == false);
}
