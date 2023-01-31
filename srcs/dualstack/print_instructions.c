/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:35:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 04:28:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_list *instructions)
{
	while (instructions != NULL)
	{
		ft_printf("%s\n", instructions->content);
		instructions = instructions->next;
	}
}
