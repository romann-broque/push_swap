/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/21 00:26:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_remove_useless_push(t_list **parent)
{
	t_list	*tmp;

	if (ft_lstsize(*parent) >= 2
		&& ((ft_strcmp((*parent)->content, "pb") == 0 && ft_strcmp((*parent)->next->content, "pa") == 0)
			|| (ft_strcmp((*parent)->content, "pa") == 0 && ft_strcmp((*parent)->next->content, "pb") == 0)))
	{
		tmp = (*parent)->next->next;
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
		*parent = tmp;
	}
}

void	remove_useless_push(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 2)
	{
		if ((ft_strcmp((*parent)->next->content, "pa") == 0
				&& ft_strcmp((*parent)->next->next->content, "pb") == 0)
			|| (ft_strcmp((*parent)->next->content, "pb") == 0
				&& ft_strcmp((*parent)->next->next->content, "pa") == 0))
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

///////////////////////////

void	pre_remove_useless_pushswap(t_list **parent)
{
	if (ft_lstsize(*parent) >= 4
		&& ft_strcmp((*parent)->content, "pb") == 0
		&& ft_strcmp((*parent)->next->content, "sb") == 0
		&& ft_strcmp((*parent)->next->next->content, "pa") == 0
		&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0)
	{
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
		(*parent)->content = "pa";
		(*parent)->next->content = "sa";
	}
}

void	remove_useless_pushswap(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 4)
	{
		if (ft_strcmp((*parent)->next->content, "pb") == 0
			&& ft_strcmp((*parent)->next->next->content, "sb") == 0
			&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0
			&& ft_strcmp((*parent)->next->next->next->next->content, "pa") == 0)
		{
			ft_lstremove(&((*parent)->next), NULL);
			ft_lstremove(&((*parent)->next), NULL);
			(*parent)->next->content = "pa";
			(*parent)->next->next->content = "sa";
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

////////////////////////////

void	fact_push_rotate(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 3)
	{
		if (ft_strcmp((*parent)->next->content, "pb") == 0
			&& ft_strcmp((*parent)->next->next->content, "rb") == 0
			&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0)
		{
			ft_lstremove(&((*parent)->next), NULL);
			ft_lstremove(&((*parent)->next), NULL);
			(*parent)->next->content = "ra";
			fact_push_rotate(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			fact_push_rotate(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}

void	rotate_fact1(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 2)
	{
		if ((ft_strcmp((*parent)->next->content, "ra") == 0
				&& ft_strcmp((*parent)->next->next->content, "rb") == 0)
			|| (ft_strcmp((*parent)->next->content, "rb") == 0
				&& ft_strcmp((*parent)->next->next->content, "ra") == 0))
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
		if ((ft_strcmp((*parent)->next->content, "rra") == 0
				&& ft_strcmp((*parent)->next->next->content, "rrb") == 0)
			|| (ft_strcmp((*parent)->next->content, "rrb") == 0
				&& ft_strcmp((*parent)->next->next->content, "rra") == 0))
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
/*
void	convert_to_swap(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 3)
	{
		if (ft_strcmp((*parent)->next->content, "pb") == 0
			&& ft_strcmp((*parent)->next->next->content, "ra") == 0
			&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0)
		{
			ft_lstremove(&((*parent)->next), NULL);
			ft_lstremove(&((*parent)->next), NULL);
			(*parent)->next->content = "ra";
			fact_push_rotate(&((*parent)->next));
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			fact_push_rotate(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}
*/

void	fact_instructions(t_list **parent)
{
	//print_instructions(*parent);
	//printf("<------->\n");
	//remove_useless_pushback(parent);
	pre_remove_useless_pushswap(parent);
	remove_useless_pushswap(parent);
	remove_useless_push(parent);
	rotate_fact1(parent);
	fact_push_rotate(parent);
	rotate_fact2(parent);
	pre_remove_useless_push(parent);
	remove_useless_push(parent);
}
