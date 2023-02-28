/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:53:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 22:05:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	index_of(const char *str, const char c)
{
	ssize_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	if (str[index] != c)
		return (-1);
	return (index);
}
