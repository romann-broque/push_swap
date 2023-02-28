/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:54:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 19:06:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	sort_stack(char **numbers, char **instructions)
{
	const size_t	size = get_array_size(numbers);
	t_dualstack		dual;
	t_stack			*stack;
	int				ret_val;

	ret_val = EXIT_FAILURE;
	stack = get_numbers(numbers, size);
	init_dualstack(&dual, stack, size);
	dual.instructions = gen_instructions_list(instructions);
	apply_instructions(&dual);
	if (is_stack_valid(dual.a) == true && dual.b == NULL)
		ret_val = EXIT_SUCCESS;
	free(stack);
	ft_lstclear(&(dual.a), NULL);
	free_dualstack(&dual);
	return (ret_val);
}

int	checker(char **strs)
{
	char	**instructions;
	char	**numbers;
	int		ret_val;

	ret_val = EXIT_FAILURE;
	instructions = NULL;
	numbers = get_arguments(strs);
	if (are_nb_valid(numbers) == true)
	{
		instructions = get_instructions();
		if (are_instructions_valid(instructions) == false)
			ret_val = EXIT_ERROR;
		else if (sort_stack(numbers, instructions) == EXIT_SUCCESS)
			ret_val = EXIT_SUCCESS;
	}
	free_strs(numbers);
	free_strs(instructions);
	return (ret_val);
}

int	main(const int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_SUCCESS;
	if (ac > 1)
	{
		ret_val = checker(av + 1);
		print_result(ret_val);
	}
	return (ret_val != EXIT_SUCCESS);
}
