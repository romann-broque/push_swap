/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:22:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 15:30:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((uint8_t *)s1)[i] != ((uint8_t *)s2)[i])
			return (((uint8_t *)s1)[i] - ((uint8_t *)s2)[i]);
		++i;
	}
	return (0);
}
