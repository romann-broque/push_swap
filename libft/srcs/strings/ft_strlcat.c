/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:19:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 00:23:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	size_src = ft_strlen(src);
	size_t			size_dest;

	if (dst == NULL)
		size_dest = 0;
	else
		size_dest = ft_strlen(dst);
	if (dstsize <= size_dest)
		return (dstsize + size_src);
	ft_strlcpy(dst + size_dest, src, dstsize - size_dest);
	return (size_dest + size_src);
}
