/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:44:35 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 18:47:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new;

	new = (char *)malloc((n + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, s, n + 1);
	return (new);
}
