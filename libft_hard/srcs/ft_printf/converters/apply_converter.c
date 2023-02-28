/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:18:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 15:02:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	get_type(ssize_t index)
{
	t_type	type;

	type = NO_TYPE;
	if (index >= 0)
	{
		type = 0x0001;
		type <<= index;
	}
	return (type);
}

size_t	apply_converter(t_machine *machine)
{
	static char	*(*conv[])(t_arg *) = {char_type, nb_type};
	const char	curr_c = *(machine->input);
	ssize_t		index;
	char		*string;

	index = get_index(OPTIONS, curr_c);
	if (index != -1)
	{
		machine->arg->type = get_type(index);
		string = conv[!(machine->arg->type & CHAR_TYPE)](machine->arg);
	}
	else
		string = fill_unknown(machine);
	cpy_to_buffer(machine, string);
	free(string);
	return (curr_c != '\0');
}
