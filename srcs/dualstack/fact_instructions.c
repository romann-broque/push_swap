/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 02:09:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fact_instructions(t_list *parent)
{
	t_list	*tmp;

	while (parent != NULL && parent->next != NULL && parent->next->next != NULL)
	{
		if (ft_strcmp(parent->next->content, "pb") == 0 && ft_strcmp(parent->next->next->content, "pa") == 0)
		{
			ft_lstremove(&parent, NULL);
			ft_lstremove(&(parent), NULL);
			break ;
		}
		else
		{
			tmp = parent->next->next;
			fact_instructions(parent->next);
			if (tmp == parent->next->next)
				break ;
		}
	}
}
