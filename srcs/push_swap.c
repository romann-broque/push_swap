/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 19:00:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **strs)
{
	char **const	arg = get_arguments(strs);
	const size_t	count = get_strs_size(arg);
	t_dualstack		dual;
	t_stack			*numbers;

	if (are_nb_valid(arg) == true)
	{
		numbers = get_numbers(arg, count);
		init_dualstack(&dual, numbers, count);
		sort_dualstack(&dual);
		free_dualstack(&dual);
		free(numbers);
	}
	else
		ft_dprintf(STDERR_FILENO, "ERROR\n");
	free_strs(arg);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(av + 1);
	return (EXIT_SUCCESS);
}
