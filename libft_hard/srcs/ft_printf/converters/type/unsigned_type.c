/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:59 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 18:04:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_type(t_arg *arg)
{
	const unsigned long	nb = va_arg(arg->aptr, unsigned long);
	char				*precision_part;
	char				*conv_out;
	char				*output;

	output = NULL;
	if (nb != 0 || arg->precision != 0)
	{
		if (arg->type & HEX_TYPE)
			conv_out = hex_type(arg, nb);
		else
			conv_out = u_integer(nb);
		precision_part = get_precision(arg->precision, conv_out);
		output = ft_strnjoin(output, precision_part, ft_strlen(precision_part));
		output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
		free(precision_part);
		free(conv_out);
	}
	if (output != NULL)
		arg->size += ft_strlen(output);
	add_width(&output, arg);
	return (output);
}
