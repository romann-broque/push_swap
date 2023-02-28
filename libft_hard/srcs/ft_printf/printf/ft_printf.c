/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 14:58:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		ret_val;
	va_list	aptr;

	va_start(aptr, str);
	ret_val = ft_vdprintf(STDOUT_FILENO, str, aptr);
	va_end(aptr);
	return (ret_val);
}
