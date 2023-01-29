/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 01:35:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_numbers(char **arg, const size_t count)
{
	size_t	i;
	int		*numbers;

	numbers = (int *)malloc((count) * sizeof(int));
	if (numbers != NULL)
	{
		i = 0;
		while (i < count)
		{
			numbers[i] = ft_atoi(arg[i]);
			++i;
		}
	}
	return (numbers);
}

void	push_swap(char **arg, const size_t count)
{
	t_list	*root;
	int		*numbers;

	numbers = get_numbers(arg, count);
	root = gen_list(numbers, count);
	ft_lstprint(root);
	ft_lstclear(&root, NULL);
	free(numbers);
}


int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(av + 1, ac - 1);
	return (EXIT_SUCCESS);
}
