/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:58:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 12:01:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

size_t	abs_index(const char *buffer, const char c)
{
	const ssize_t	index = index_of(buffer, c);

	if (index == -1)
		return (ft_strlen(buffer));
	return (index);
}
