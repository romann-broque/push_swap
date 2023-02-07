/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:54:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/07 11:49:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	get_array_size(char **strs)
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

static size_t	get_str_index(const char array[11][4], const char *str)
{
	size_t	index;

	index = 0;
	while (array[index] != NULL && ft_strcmp(array[index], str) != 0)
		++index;
	return (index);
}

static void	apply_instructions(t_dualstack *dual)
{
	const char	operations[11][4] = {
		"pa",
		"pb",
		"sa",
		"sb",
		"ss",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};
	static void	(*fct[])(t_dualstack *) = {
		pa_fct,
		pb_fct,
		sa_fct,
		sb_fct,
		ss_fct,
		ra_fct,
		rb_fct,
		rr_fct,
		rra_fct,
		rrb_fct,
		rrr_fct,
	};
	t_list		*curr_instruction;

	curr_instruction = dual->instructions;
	while (curr_instruction != NULL)
	{
		fct[get_str_index(operations, curr_instruction->content)](dual);
		curr_instruction = curr_instruction->next;
	}
}

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
	else
		print_dualstack(&dual);
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
		if (sort_stack(numbers, instructions) == EXIT_SUCCESS)
			ret_val = EXIT_SUCCESS;
	}
	free_strs(instructions);
	return (ret_val);
	// {
	// 	ret_val = is_stack_sorted(numbers);
	// }
	// return (ret_val);
}

static void	print_result(const int result)
{
	if (result == EXIT_SUCCESS)
		ft_printf("OK");
	else
		ft_printf("KO");
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
	ft_printf("\n");
	return (ret_val);
}
