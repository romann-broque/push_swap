/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:29:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 04:31:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getprintf(const char *str, ...)
{
	static size_t		(*state_function[])(t_machine *) = {
		standard_state,
		mod_state,
		width_state,
		precision_state,
		conv_state};
	t_machine			*machine;
	t_output			*output;
	va_list				aptr;
	char				*final_output;

	va_start(aptr, str);
	machine = init_machine(str, aptr, STDOUT_FILENO);
	output = machine->output;
	while (machine->state != E_END)
		machine->input += state_function[machine->state](machine);
	output->final_str = add_strn(output->final_str, output->total_size,
			output->buffer, output->index);
	output->total_size += output->index;
	final_output = ft_strdup(output->final_str);
	free_machine(machine);
	va_end(aptr);
	return (final_output);
}
