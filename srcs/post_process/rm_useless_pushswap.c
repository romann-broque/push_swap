/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_useless_pushswap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:39:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/24 15:54:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_useless_pushswap(t_list **parent)
{
	return (ft_strcmp((*parent)->content, "pb") == 0
		&& ft_strcmp((*parent)->next->content, "sb") == 0
		&& ft_strcmp((*parent)->next->next->content, "pa") == 0
		&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0);
}

static void	replace_useless_pushswap(t_list **parent)
{
	ft_lstremove(parent, NULL);
	ft_lstremove(parent, NULL);
	(*parent)->content = "pa";
	(*parent)->next->content = "sa";
}

void	pre_remove_useless_pushswap(t_list **parent)
{
	if (ft_lstsize(*parent) >= 4 && is_useless_pushswap(parent) == true)
		replace_useless_pushswap(parent);
}

void	remove_useless_pushswap(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 4)
	{
		if (is_useless_pushswap(&(*parent)->next) == true)
		{
			replace_useless_pushswap(&((*parent)->next));
			remove_useless_pushswap(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			remove_useless_pushswap(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}
