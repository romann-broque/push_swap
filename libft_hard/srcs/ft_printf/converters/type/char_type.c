/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 17:45:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_type(t_arg *arg)
{
	static char		*(*converters[])() = {character, string, percentage};
	size_t			type_index;
	char			*output;

	type_index = get_index_from_type(arg->type, CHAR_TYPE);
	output = converters[type_index](arg);
	if (!(arg->type & PERCENTAGE_TYPE))
		add_width(&output, arg);
	return (output);
}
