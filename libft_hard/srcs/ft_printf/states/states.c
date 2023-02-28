/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 14:31:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_state(t_machine *machine)
{
	size_t	offset;

	offset = apply_converter(machine);
	machine->arg->size = 0;
	machine->arg->type = NO_TYPE;
	machine->arg->flags = NO_FLAG;
	machine->arg->width = 0;
	machine->arg->precision = UNSET_PRECISION;
	machine->state = E_STANDARD;
	return (offset);
}

size_t	mod_state(t_machine *machine)
{
	const char	curr_c = *machine->input;
	size_t		input_offset;
	ssize_t		flag_index;

	input_offset = 0;
	flag_index = get_index(FLAGS, curr_c);
	if (flag_index > -1)
	{
		get_flag(&machine->arg->flags, flag_index);
		++input_offset;
	}
	else
		machine->state = E_WIDTH;
	return (input_offset);
}

size_t	width_state(t_machine *machine)
{
	size_t	input_offset;

	input_offset = 0;
	if (ft_isdigit(*machine->input) != 0)
	{
		machine->arg->width = ft_atol(machine->input);
		input_offset = get_nbsize(machine->arg->width, 10);
	}
	machine->state = E_PRECISION;
	return (input_offset);
}

size_t	precision_state(t_machine *machine)
{
	size_t	input_offset;

	input_offset = 0;
	if (*machine->input == *PRECISION_CHAR)
	{
		++input_offset;
		machine->arg->precision = 0;
		if (ft_isdigit(machine->input[1]) != 0)
		{
			machine->arg->precision = ft_atol(machine->input + 1);
			input_offset += get_precision_size(machine->input + 1,
					machine->arg);
		}
		else if (ft_strchr(OPTIONS, machine->input[1]) == NULL)
		{
			fill_invalid_precision(machine);
			machine->state = E_STANDARD;
		}
	}
	else
		machine->state = E_CONV;
	return (input_offset);
}

size_t	standard_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == END_CHAR)
		machine->state = E_END;
	else if (curr_c == *OPTION_CHAR)
		machine->state = E_MOD;
	else
		cpy_data(machine->output, (char *)machine->input, sizeof(char));
	return (1);
}
