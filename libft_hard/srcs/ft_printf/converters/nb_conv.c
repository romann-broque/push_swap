/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:57:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 15:51:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer_d(int nb)
{
	char	*nb_str;
	char	*output;

	output = NULL;
	nb_str = itoa_base(get_abs(nb), DEC);
	output = add_str(output, nb_str, ft_strlen(nb_str));
	free(nb_str);
	return (output);
}

char	*integer_i(int nb)
{
	return (integer_d(nb));
}

char	*u_integer(unsigned long nb)
{
	char				*nb_str;
	char				*output;

	output = NULL;
	nb_str = itoa_base(nb, DEC);
	output = add_str(output, nb_str, ft_strlen(nb_str));
	free(nb_str);
	return (output);
}
