/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:55:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 15:01:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_width_unit(t_arg *arg, t_type type)
{
	if (arg->precision == UNSET_PRECISION
		&& (size_t)arg->precision > arg->width
		&& arg->flags & ZERO_FLAG
		&& !(arg->flags & MINUS_FLAG)
		&& type & NB_TYPE)
		return (WIDTH_UNIT[1]);
	return (WIDTH_UNIT[0]);
}

size_t	get_output_size(const char *string, const t_arg *arg)
{
	size_t	size;

	size = 0;
	if (string != NULL)
	{
		size = ft_strlen(string);
		if (size == 0)
			size = !(!(arg->type & CHARACTER_TYPE));
	}
	return (size);
}

void	cpy_to_buffer(t_machine *machine, char *string)
{
	const size_t	size = machine->arg->size;

	cpy_data(machine->output, string, size);
}

void	add_width(char **output, t_arg *arg)
{
	char	*padding;
	char	*tmp;
	char	width_unit;

	arg->width = reduce_size(arg->width, arg->size);
	width_unit = get_width_unit(arg, arg->type);
	padding = strset(width_unit, arg->width);
	if (padding == NULL || *padding == '\0')
	{
		free(padding);
		return ;
	}
	if (arg->flags & MINUS_FLAG)
		*output = add_strn(*output, arg->size, padding, arg->width);
	else
	{
		tmp = *output;
		*output = add_strn(padding, arg->width, *output, arg->size);
		padding = NULL;
		free(tmp);
	}
	arg->size += arg->width;
	free(padding);
}
