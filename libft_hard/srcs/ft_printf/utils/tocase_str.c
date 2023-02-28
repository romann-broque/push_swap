/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tocase_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:00:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 18:08:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*toupper_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		++i;
	}
	return (str);
}

char	*tolower_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		++i;
	}
	return (str);
}
