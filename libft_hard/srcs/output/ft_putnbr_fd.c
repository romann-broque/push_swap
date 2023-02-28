/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:06:37 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/07 18:44:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nb(unsigned int n, int fd)
{
	if (n > 0)
	{
		print_nb(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		abs_n = -n;
	}
	else
		abs_n = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		print_nb(abs_n, fd);
}
