/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:54:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 14:26:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_precision(ssize_t precision, char *string)
{
	if (precision > INT_MAX)
		return (NULL);
	if (precision == UNSET_PRECISION)
		precision = 0;
	precision = reduce_size(precision, ft_strlen(string));
	return (strset('0', precision));
}

size_t	get_precision_size(const char *input, const t_arg *arg)
{
	size_t	size;

	size = 0;
	while (input[size] == '0')
		++size;
	if (arg->precision > 0)
		size += get_nbsize(arg->precision, 10);
	return (size);
}
