/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:40:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 13:41:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*gen_list(int *numbers, const size_t count)
{
	t_list	*root;
	t_list	*curr;
	size_t	i;

	root = NULL;
	i = 0;
	while (i < count)
	{
		curr = ft_lstnew(numbers + i);
		ft_lstadd_back(&root, curr);
		++i;
	}
	return (root);
}

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
