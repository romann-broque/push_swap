/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:35:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 15:05:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign(int nb, char **output, t_arg *arg)
{
	if (nb >= 0)
	{
		if (arg->flags & PLUS_FLAG)
			prefix_add(PLUS_SIGN, output);
		else if (arg->flags & SPACE_FLAG)
			prefix_add(SPACE_PAT, output);
	}
	else
		prefix_add(MINUS_SIGN, output);
}

void	add_beginning(int nb, char **output, t_arg *arg)
{
	if (arg->precision == UNSET_PRECISION
		&& arg->flags & ZERO_FLAG && !(arg->flags & MINUS_FLAG))
	{
		add_width(output, arg);
		add_sign(nb, output, arg);
	}
	else
	{
		add_sign(nb, output, arg);
		add_width(output, arg);
	}
}

static void	apply_nb_flag(t_arg *arg, char **output, const char *conv_out)
{
	*output = ft_strnjoin(*output, conv_out, ft_strlen(conv_out));
	if (arg->flags & PREFIX_FLAG)
	{
		prefix_add(PREFIX_HEX, output);
		arg->size += ft_strlen(PREFIX_HEX);
		if (arg->type & UP_TYPE)
			*output = toupper_str(*output);
	}
	if ((arg->flags & SPACE_FLAG)
		&& !(arg->flags & PLUS_FLAG) && (arg->type & HEX_TYPE))
	{
		prefix_add(SPACE_PAT, output);
		arg->size += ft_strlen(SPACE_PAT);
	}
}

char	*nb_type(t_arg *arg)
{
	static char		*(*converters[])(t_arg *) = {
		signed_type, unsigned_type};
	const ssize_t	type_index = !(arg->type & SIGNED_TYPE);
	char			*conv_out;
	char			*output;

	output = NULL;
	conv_out = NULL;
	if (arg->precision <= INT_MAX)
		conv_out = converters[type_index](arg);
	if (conv_out != NULL)
		apply_nb_flag(arg, &output, conv_out);
	free(conv_out);
	return (output);
}
