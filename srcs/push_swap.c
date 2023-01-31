/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 18:22:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **arg, const size_t count)
{
	t_dualstack	dual;
	t_stack		*numbers;

	numbers = get_numbers(arg, count);
	init_dualstack(&dual, numbers, count);
	sort_dualstack(&dual);
	free_dualstack(&dual);
	free(numbers);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(av + 1, ac - 1);
	return (EXIT_SUCCESS);
}
