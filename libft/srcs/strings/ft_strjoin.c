/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:30:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 01:02:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		new = NULL;
	else
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (new != NULL)
		{
			ft_memcpy(new, s1, len1);
			ft_memcpy(new + len1, s2, len2);
			new[len1 + len2] = '\0';
		}
	}
	return (new);
}
