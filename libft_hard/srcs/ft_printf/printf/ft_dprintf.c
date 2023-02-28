/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:57:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 14:58:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	int		ret_val;
	va_list	aptr;

	va_start(aptr, str);
	ret_val = ft_vdprintf(fd, str, aptr);
	va_end(aptr);
	return (ret_val);
}
