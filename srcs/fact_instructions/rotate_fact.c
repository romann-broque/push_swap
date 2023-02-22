/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:43:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/21 17:23:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_rotate(t_list **parent)
{
	return ((ft_strcmp((*parent)->next->content, "ra") == 0
			&& ft_strcmp((*parent)->next->next->content, "rb") == 0)
		|| (ft_strcmp((*parent)->next->content, "rb") == 0
			&& ft_strcmp((*parent)->next->next->content, "ra") == 0));

}

static bool	is_rev_rotate(t_list **parent)
{
	return ((ft_strcmp((*parent)->next->content, "rra") == 0
			&& ft_strcmp((*parent)->next->next->content, "rrb") == 0)
		|| (ft_strcmp((*parent)->next->content, "rrb") == 0
			&& ft_strcmp((*parent)->next->next->content, "rra") == 0));
}

void	rotate_fact1(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 2)
	{
		if (is_rotate(parent) == true)
		{
			ft_lstremove(&(*parent)->next, NULL);
			(*parent)->next->content = "rr";
			rotate_fact1(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			rotate_fact1(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}

void	rotate_fact2(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 2)
	{
		if (is_rev_rotate(parent) == true)
		{
			ft_lstremove(&(*parent)->next, NULL);
			(*parent)->next->content = "rrr";
			rotate_fact2(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			rotate_fact2(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}
