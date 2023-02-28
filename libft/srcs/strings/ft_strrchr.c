/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:51:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/04 01:03:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_ptr;

	last_ptr = NULL;
	c = (char)c;
	while (*s != '\0')
	{
		if (*s == c)
			last_ptr = (char *)s;
		++s;
	}
	if (c == '\0')
		last_ptr = (char *)s;
	return (last_ptr);
}
