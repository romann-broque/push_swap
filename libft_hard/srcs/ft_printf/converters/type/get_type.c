/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/22 19:14:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remove_flag(t_flag *flags, t_flag removing_flag)
{
	if (*flags & removing_flag)
		*flags ^= removing_flag;
}

void	add_flag(t_flag *flags, t_flag adding_flag)
{
	*flags |= adding_flag;
}

size_t	get_index_from_type(t_type type, t_type mask)
{
	size_t	index;

	index = 0;
	while (!(type & 0x01) && type & mask)
	{
		type >>= 1;
		++index;
	}
	return (index);
}

void	get_flag(t_flag *flags, const ssize_t flag_index)
{
	ssize_t	i;
	t_flag	flag;

	flag = NO_FLAG;
	i = 0;
	while (i <= flag_index)
	{
		flag <<= 1;
		++i;
	}
	*flags |= flag;
}
