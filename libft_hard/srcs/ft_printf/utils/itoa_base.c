/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:30:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 15:27:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_nbsize(unsigned long nb, const size_t len_base)
{
	size_t	size;

	size = (nb == 0);
	while (nb != 0)
	{
		nb /= len_base;
		++size;
	}
	return (size);
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

char	*itoa_base(unsigned long nb, const char *base)
{
	const size_t	len_base = ft_strlen(base);
	size_t			nb_size;
	size_t			i;
	char			*str;

	str = NULL;
	if (is_valid_base(base) == true)
	{
		nb_size = get_nbsize(nb, len_base);
		str = (char *)malloc((nb_size + 1) * sizeof(char));
		if (str != NULL)
		{
			i = 0;
			while (i < nb_size)
			{
				str[nb_size - i - 1] = base[nb % len_base];
				nb /= len_base;
				++i;
			}
			str[nb_size] = '\0';
		}
	}
	return (str);
}
