/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:45:21 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 21:48:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, const char *s2, const size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	if (len2 > n)
		len2 = n;
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		if (s1 != NULL)
			ft_strncpy(new, (char *)s1, len1 + 1);
		if (s2 != NULL)
			ft_strncpy(new + len1, (char *)s2, len2 + 1);
		new[len1 + len2] = '\0';
	}
	free(s1);
	return (new);
}
