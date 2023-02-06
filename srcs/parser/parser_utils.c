/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:43:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 17:45:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_strs_size(char **strs)
{
	size_t	size;

	size = 0;
	while (strs[size] != NULL)
		++size;
	return (size);
}

static void	fill_dup_strs(char **dest, char **src)
{
	size_t	i;

	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = ft_strdup(src[i]);
		++i;
	}
	dest[i] = NULL;
}

void	add_strs(char ***dest, char **src, const size_t size2)
{
	size_t	size1;
	char	**new;

	size1 = 0;
	if (*dest != NULL)
		size1 = get_strs_size(*dest);
	new = (char **)malloc((size1 + size2 + 1) * sizeof(char *));
	if (new != NULL)
	{
		if (*dest != NULL)
			fill_dup_strs(new, *dest);
		fill_dup_strs(new + size1, src);
		new[size1 + size2] = NULL;
	}
	free_strs(*dest);
	*dest = new;
}

void	cpy_arg(char ***dest, char **arg)
{
	const size_t	size = get_strs_size(arg);

	add_strs(dest, arg, size);
}
