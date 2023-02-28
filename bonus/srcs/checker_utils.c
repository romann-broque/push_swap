/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:41:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 17:45:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	get_array_size(char **strs)
{
	size_t	size;

	size = 0;
	while (strs[size] != NULL)
		++size;
	return (size);
}

t_list	*gen_instructions_list(char **elements)
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

size_t	get_str_index(const char array[OP_COUNT][OP_MAX_LEN], const char *str)
{
	size_t	index;

	index = 0;
	while (array[index] != NULL && ft_strcmp(array[index], str) != 0)
		++index;
	return (index);
}

void	print_result(const int result)
{
	if (result == EXIT_SUCCESS)
		ft_printf("OK");
	else
		ft_printf("KO");
}

void	apply_instructions(t_dualstack *dual)
{
	const char	operations[OP_COUNT][OP_MAX_LEN] = {
		"pa", "pb", "sa", "sb",
		"ss", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};
	static void	(*fct[])(t_dualstack *) = {
		pa_fct, pb_fct, sa_fct, sb_fct,
		ss_fct, ra_fct, rb_fct, rr_fct,
		rra_fct, rrb_fct, rrr_fct,
	};
	t_list		*curr_instruction;

	curr_instruction = dual->instructions;
	while (curr_instruction != NULL)
	{
		fct[get_str_index(operations, curr_instruction->content)](dual);
		curr_instruction = curr_instruction->next;
	}
}
