/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:46:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 21:49:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const size_t	size = ft_strlen(s) + 1;
	char			*dup;

	dup = (char *)malloc(size);
	if (dup != NULL)
		ft_strlcpy(dup, s, size);
	return (dup);
}
