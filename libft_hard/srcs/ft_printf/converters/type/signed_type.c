/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 14:43:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_type(t_arg *arg)
{
	static char		*(*converters[])(int) = {integer_d, integer_i};
	const ssize_t	type_index = get_index_from_type(arg->type,
			SIGNED_TYPE) - 1;
	const int		nb = va_arg(arg->aptr, int);
	char			*conv_out;
	char			*output;

	output = NULL;
	if (nb != 0 || arg->precision != 0)
	{
		conv_out = converters[type_index](nb);
		output = ft_strnjoin(get_precision(arg->precision, conv_out),
				conv_out, ft_strlen(conv_out));
		arg->size = ft_strlen(output)
			+ ((arg->flags & PLUS_FLAG)
				|| (nb < 0)
				|| (arg->flags & SPACE_FLAG));
		free(conv_out);
	}
	add_beginning(nb, &output, arg);
	return (output);
}
