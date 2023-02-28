/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:31:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 17:31:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	reduce_to_precision(size_t len, ssize_t precision)
{
	size_t	final_len;

	final_len = len;
	if (precision != UNSET_PRECISION && final_len > (size_t)precision)
			final_len = precision;
	return (final_len);
}

char	*character(t_arg *arg)
{
	const int	c = va_arg(arg->aptr, int);

	arg->size += sizeof(char);
	return (to_string(c));
}

char	*string(t_arg *arg)
{
	const char	*str = va_arg(arg->aptr, char *);
	char		*output;
	size_t		len;
	size_t		final_len;

	if (str == NULL)
	{
		len = ft_strlen(NULL_DEF);
		final_len = reduce_to_precision(len, arg->precision);
		if (final_len < len)
			final_len = 0;
		output = ft_strndup(NULL_DEF, final_len);
	}
	else
	{
		final_len = ft_strlen(str);
		if (arg->precision != UNSET_PRECISION)
			final_len = reduce_to_precision(final_len, arg->precision);
		output = ft_strndup(str, final_len);
	}
	if (output != NULL)
		arg->size += ft_strlen(output);
	return (output);
}

char	*percentage(t_arg *arg)
{
	arg->size += sizeof(char);
	return (to_string(*OPTION_CHAR));
}
