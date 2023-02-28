/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:25:12 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 14:21:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_str(char *s1, const char *s2, const size_t n)
{
	size_t	size;

	size = 0;
	if (s1 != NULL)
		size = ft_strlen(s1);
	return (add_strn(s1, size, s2, n));
}

char	*add_strn(char *s1, const size_t n1, const char *s2, const size_t n2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	len1 = 0;
	if (s1 != NULL)
		len1 = n1;
	len2 = n2;
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		ft_memcpy(new, (char *)s1, len1);
		ft_memcpy(new + len1, (char *)s2, len2);
		new[len1 + len2] = '\0';
	}
	free(s1);
	return (new);
}
