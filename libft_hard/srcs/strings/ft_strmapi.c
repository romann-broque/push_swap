/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:08:56 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 11:19:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*new;

	if (s == NULL)
		new = NULL;
	else if (f == NULL)
		new = ft_strdup(s);
	else
	{
		len = ft_strlen(s);
		new = (char *)malloc((len + 1) * sizeof(char));
		if (new != NULL)
		{
			i = 0;
			while (i < len)
			{
				new[i] = f(i, s[i]);
				++i;
			}
			new[len] = '\0';
		}
	}
	return (new);
}
