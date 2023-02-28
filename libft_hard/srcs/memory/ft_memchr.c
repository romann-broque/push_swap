/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:55:30 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/20 22:59:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	c = (uint8_t)c;
	while (i < n)
	{
		if (((uint8_t *)s)[i] == c)
			return ((void *)(s + i));
		++i;
	}
	return (NULL);
}
