/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:28:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 14:44:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dualstack(t_dualstack *dual)
{
	sa(dual);
}

void	sort_stack(t_list *stack_a)
{
	t_dualstack	dual;

	dual.a = stack_a;
	dual.b = NULL;
	sort_dualstack(&dual);
}

void	push_swap(char **arg, const size_t count)
{
	t_list	*root;
	int		*numbers;

	numbers = get_numbers(arg, count);
	root = gen_list(numbers, count);
	ft_lstprint(root);
	sort_stack(root);
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
