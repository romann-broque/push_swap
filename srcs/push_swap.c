/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 15:24:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(const char **arg, const size_t count)
{
	t_dualstack	dual;
	t_stack		*numbers;

	if (are_nb_valid(arg) == true)
	{
		numbers = get_numbers(arg, count);
		init_dualstack(&dual, numbers, count);
		sort_dualstack(&dual);
		free_dualstack(&dual);
		free(numbers);
	}
	else
		ft_printf("ERROR\n");
}

int	main(int ac, const char **av)
{
	if (ac > 1)
		push_swap(av + 1, ac - 1);
	return (EXIT_SUCCESS);
}
