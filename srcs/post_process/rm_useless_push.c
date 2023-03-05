/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_useless_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:38:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/03/05 18:32:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_useless_push(t_list **parent)
{
	return ((ft_strcmp((*parent)->content, "pb") == 0
			&& ft_strcmp((*parent)->next->content, "pa") == 0)
		|| (ft_strcmp((*parent)->content, "pa") == 0
			&& ft_strcmp((*parent)->next->content, "pb") == 0));
}

void	pre_remove_useless_push(t_list **parent)
{
	t_list	*tmp;

	if (ft_lstsize(*parent) >= 2 && is_useless_push(parent) == true)
	{
		tmp = (*parent)->next->next;
		ft_lstdelone((*parent)->next, NULL);
		ft_lstdelone(*parent, NULL);
		*parent = tmp;
	}
}

void	remove_useless_push(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 2)
	{
		if (is_useless_push(&(*parent)->next) == true)
		{
			ft_lstremove(parent, NULL);
			ft_lstremove(parent, NULL);
			remove_useless_push(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			remove_useless_push(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}
