/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:41:44 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 17:44:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define WHITESPACES " "

char	**get_arguments(char **arg)
{
	char	**new_arg;
	char	**curr_arg;
	size_t	i;

	new_arg = NULL;
	i = 0;
	while (arg[i] != NULL)
	{
		curr_arg = ft_split_set(arg[i], WHITESPACES);
		cpy_arg(&new_arg, curr_arg);
		free_strs(curr_arg);
		++i;
	}
	return (new_arg);
}
