/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 03:39:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **arg, const size_t count)
{
	t_list	*root;
	int		*numbers;

	numbers = get_numbers(arg, count);
	root = gen_list(numbers, count);
	sort_stack(root);
	free(numbers);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(av + 1, ac - 1);
	return (EXIT_SUCCESS);
}
