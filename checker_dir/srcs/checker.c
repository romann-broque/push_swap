/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:54:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 12:19:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	get_strs_size(const char **strs)
{
	size_t	size;

	size = 0;
	while (strs[size] != NULL)
		++size;
	return (size);
}

static t_list	*gen_instructions_list(char **elements)
{
	t_list	*head;

	head = NULL;
	while (elements != NULL && *elements != NULL)
	{
		ft_contadd_back(&head, *elements);
		++(elements);
	}
	return (head);
}

static void	sort_stack(const char **numbers, char **instructions)
{
	const size_t	size = get_strs_size(numbers);
	t_dualstack		dual;
	t_stack			*stack;

	init_dualstack(&dual, stack, size);
	dual.instructions = gen_instructions_list(instructions);
	free_dualstack(&dual);
}

int	checker(const char **numbers)
{
	char	**instructions;
	int		ret_val;

	ret_val = EXIT_FAILURE;
	instructions = NULL;
	if (are_nb_valid(numbers) == true)
	{
		ret_val = EXIT_SUCCESS;
		instructions = get_instructions();
		sort_stack(numbers, instructions);
	}
	free_strs(instructions);
	return (ret_val);
	// {
	// 	ret_val = is_stack_sorted(numbers);
	// }
	// return (ret_val);
}

int	main(const int ac, const char **av)
{
	int	ret_val;

	ret_val = EXIT_SUCCESS;
	if (ac > 1)
		ret_val = checker(av + 1);
	return (ret_val);
}
