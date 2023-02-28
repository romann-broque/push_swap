/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_instructions_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:31:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 18:33:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_instruction_valid(char *instruction)
{
	const char	operations[OP_COUNT][OP_MAX_LEN] = {
		"pa", "pb", "sa", "sb",
		"ss", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};
	size_t		i;

	i = 0;
	while (i < OP_COUNT && ft_strcmp(instruction, operations[i]) != 0)
		++i;
	return (i < OP_COUNT && ft_strcmp(instruction, operations[i]) == 0);
}

bool	are_instructions_valid(char **instructions)
{
	while (instructions != NULL && *instructions != NULL
		&& is_instruction_valid(*instructions) == true)
		++instructions;
	return (instructions == NULL);
}
