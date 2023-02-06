/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:30:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 00:22:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_stdin_reading(void)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	ssize_t	bytes_count;

	content = NULL;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes_count = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (bytes_count > 0)
	{
		content = ft_strnjoin(content, buffer, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE);
		bytes_count = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	}
	return (content);
}

char	**get_instructions(void)
{
	char	*content;
	char	**instructions;

	content = get_stdin_reading();
	instructions = ft_split(content, '\n');
	free(content);
	return (instructions);
}
