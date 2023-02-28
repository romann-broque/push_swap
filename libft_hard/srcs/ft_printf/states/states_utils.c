/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 14:31:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_unknown(t_machine *machine)
{
	char	*string;
	size_t	len;

	len = 0;
	if (machine->input[0] != '\0' && machine->input[1] != '\0')
		len += 1 + (machine->input[2] != '\0');
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string != NULL)
	{
		string[len] = '\0';
		if (len > 0)
			string[0] = *OPTION_CHAR;
		if (len > 1)
			string[1] = *machine->input;
		machine->arg->size += ft_strlen(string);
	}
	return (string);
}

void	fill_invalid_precision(t_machine *machine)
{
	char	*output;

	machine->arg->precision = 0;
	cpy_data(machine->output, OPTION_CHAR, sizeof(char));
	cpy_data(machine->output, PRECISION_CHAR, sizeof(char));
	output = integer_d(machine->arg->precision);
	cpy_data(machine->output, output, ft_strlen(output));
	free(output);
}
