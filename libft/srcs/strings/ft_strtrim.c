/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 21:13:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;

	if (s1 != NULL)
	{
		while (set != NULL && *s1 != '\0' && ft_strchr(set, *s1) != NULL)
			++s1;
		len = ft_strlen(s1);
		while (set != NULL && len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
			--len;
		trim = ft_strndup(s1, len);
	}
	else
		trim = NULL;
	return (trim);
}
