/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 17:25:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	remove_useless_push(t_list *parent)
{
	t_list	*tmp;

	while (ft_lstsize(parent) > 2)
	{
		if (ft_strcmp(parent->next->content, "pb") == 0 && ft_strcmp(parent->next->next->content, "pa") == 0)
		{
			ft_lstremove(&parent, NULL);
			ft_lstremove(&(parent->next), NULL);
			break ;
		}
		else
		{
			tmp = parent->next->next;
			remove_useless_push(parent->next);
			if (tmp == parent->next->next)
				break ;
		}
	}
}

void	remove_useless_pushswap(t_list *parent)
{
	t_list	*tmp;

	while (ft_lstsize(parent) > 3)
	{
		if (ft_strcmp(parent->next->content, "pb") == 0
			&& ft_strcmp(parent->next->next->content, "pb") == 0
			&& ft_strcmp(parent->next->next->next->content, "sb") == 0)
		{
			ft_lstremove(&parent, NULL);
			ft_lstremove(&(parent->next), NULL);
			ft_lstremove(&(parent->next->next), NULL);
			//ft_lstinsert(parent, "sa");
			break ;
		}
		else
		{
			tmp = parent->next->next;
			remove_useless_push(parent->next);
			if (tmp == parent->next->next)
				break ;
		}
	}
}

void	fact_instructions(t_list **parent)
{
	if (ft_lstsize(*parent) >= 3
		&& ft_strcmp((*parent)->content, "pb") == 0
		&& ft_strcmp((*parent)->next->content, "pb") == 0
		&& ft_strcmp((*parent)->next->next->content, "sb") == 0)
	{
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
		//insert("sb")
	}
	if (ft_lstsize(*parent) >= 2
		&& (ft_strcmp((*parent)->content, "pb") == 0 && ft_strcmp((*parent)->next->content, "pa") == 0))
	{
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
	}
	remove_useless_push(*parent);
	remove_useless_pushswap(*parent);
	//remove useless push_back
}
