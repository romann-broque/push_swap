/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/26 17:39:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strset(int c, size_t n)
{
	char	*new;

	new = (char *)malloc((n + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_memset(new, c, n);
		new[n] = '\0';
	}
	return (new);
}

char	*ft_strndup(const char *str, const size_t size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, str, size + 1);
	return (new);
}

void	prefix_add(char *prefix, char **string)
{
	const size_t	pre_len = ft_strlen(prefix);
	size_t			str_len;
	size_t			len;
	char			*new;

	if (*string == NULL)
		*string = ft_strdup(prefix);
	else
	{
		str_len = ft_strlen(*string);
		len = pre_len + str_len;
		new = (char *)malloc((len + 1) * sizeof(char));
		if (new != NULL)
		{
			ft_strcpy(new, prefix);
			ft_strcpy(new + pre_len, *string);
			free(*string);
			*string = new;
		}
	}
}

size_t	ft_strlen_sec(const char *str)
{
	size_t	len;

	if (str != NULL)
		len = ft_strlen(str);
	else
		len = 0;
	return (len);
}
