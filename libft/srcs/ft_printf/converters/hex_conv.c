/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 13:55:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(unsigned int nb)
{
	return (itoa_base(nb, HEX));
}

char	*up_hex(unsigned int nb)
{
	return (toupper_str(low_hex(nb)));
}

char	*address(void *address)
{
	char	*output;

	if (address == NULL)
		output = ft_strdup(NIL_DEF);
	else
		output = itoa_base((unsigned long)address, HEX);
	return (output);
}
