/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:20:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 17:23:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#define SPACE ' '
#define FIRST_WHITESPACE 9
#define LAST_WHITESPACE 13
*/

static char	*skip_whitespaces(const char *str)
{
	while ((*str >= FIRST_WHITESPACE && *str <= LAST_WHITESPACE)
		|| (*str == SPACE))
		++str;
	return ((char *)str);
}

static int	get_sign(const char *str)
{
	size_t	sign;

	sign = 0;
	while (*str == '+' || *str == '-')
	{
		sign += (*str == '-');
		++str;
	}
	if (sign % 2 == 1)
		return (-1);
	return (1);
}

static bool	is_valid_base(const char *base)
{
	size_t	i;
	size_t	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (false);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] != '-' && base[i] != '+')
			&& (base[i] < FIRST_WHITESPACE || base[i] > LAST_WHITESPACE)
			&& (base[i] != SPACE))
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[i] == base[j])
					return (false);
				++j;
			}
		}
		else
			return (false);
		++i;
	}
	return (true);
}

int	ft_atoi_base(const char *str, char *base)
{
	unsigned int	nb;
	int				sign;
	size_t			base_size;

	nb = 0;
	sign = 0;
	if (base != NULL && is_valid_base(base) == true)
	{
		str = skip_whitespaces(str);
		sign = get_sign(str);
		while (*str == '+' || *str == '-')
			++str;
		base_size = abs_index(base, '\0');
		while (*str != '\0' && abs_index(base, *str) < base_size)
		{
			nb = abs_index(base, *str) + nb * base_size;
			++str;
		}
	}
	return (nb * sign);
}
