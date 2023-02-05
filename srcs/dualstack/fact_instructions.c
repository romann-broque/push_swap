/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/05 17:45:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_remove_useless_push(t_list **parent)
{
	if (ft_lstsize(*parent) >= 2
		&& (ft_strcmp((*parent)->content, "pb") == 0 && ft_strcmp((*parent)->next->content, "pa") == 0))
	{
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
	}
}

void	remove_useless_push(t_list *parent)
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

////////////

void	pre_remove_useless_pushswap(t_list **parent)
{
	if (ft_lstsize(*parent) >= 3
		&& ft_strcmp((*parent)->content, "pb") == 0
		&& ft_strcmp((*parent)->next->content, "pb") == 0
		&& ft_strcmp((*parent)->next->next->content, "sb") == 0)
	{
		ft_lstremove(parent, NULL);
		ft_lstremove(parent, NULL);
		(*parent)->content = "sa";
	}
}

void	remove_useless_pushswap(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) > 3)
	{
		if (ft_strcmp((*parent)->next->content, "pb") == 0
			&& ft_strcmp((*parent)->next->next->content, "pb") == 0
			&& ft_strcmp((*parent)->next->next->next->content, "sb") == 0)
		{
			ft_lstremove(parent, NULL);
			ft_lstremove(&((*parent)->next), NULL);
			(*parent)->next->content = "sa";
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

//////////////////

static t_list	*ft_lstget(t_list *head, const size_t index)
{
	size_t	i;

	i = 0;
	while (head != NULL && i < index)
	{
		head = head->next;
		++i;
	}
	return (head);
}

static size_t	get_index_from_str(t_list *parent, const char *str)
{
	size_t	index;

	index = 0;
	while (parent != NULL && ft_strcmp(parent->content, str) != 0)
	{
		++index;
		parent = parent->next;
	}
	return (index);
}

static size_t	count_list_occurence(t_list *parent, const char *str)
{
	size_t	count;

	count = 0;
	while (parent != NULL)
	{
		if (ft_strcmp(parent->content, str) == 0)
			++count;
		parent = parent->next;
	}
	return (count);
}

static void	remove_last_pa(t_list **parent)
{
	if (*parent != NULL)
	{
		ft_lstclear(&((*parent)->next), NULL);
		(*parent)->next = NULL;
	}
}

void	remove_useless_pushback(t_list **parent)
{
	const size_t	count_pb = count_list_occurence(*parent, "pb");
	const size_t	index_pa = get_index_from_str(*parent, "pa");
	t_list			*begin_pa;

	if (index_pa + count_pb == 0)
		ft_lstclear(parent, NULL);
	else
	{
		begin_pa = ft_lstget(*parent, index_pa + count_pb - 1);
		remove_last_pa(&begin_pa);
	}
}

///////////////////

static void	add_rotation1(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) >= 2)
	{
		if ((ft_strcmp((*parent)->content, "sa") == 0) && (ft_strcmp((*parent)->next->content, "pb") == 0))
		{
			ft_lstinsert(parent, "ra");
			ft_lstinsert(parent, "ra");
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			add_rotation1(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}

static void	add_rotation2(t_list **parent)
{
	t_list	*tmp;

	while (ft_lstsize(*parent) >= 2)
	{
		if ((ft_strcmp((*parent)->content, "sa") == 0)
			&& (ft_strcmp((*parent)->next->content, "pa") == 0))
		{
			ft_lstinsert(parent, "rra");
			ft_lstinsert(parent, "rra");
			break ;
		}
		else
		{
			tmp = (*parent)->next->next;
			add_rotation2(&((*parent)->next));
			if (tmp == (*parent)->next->next)
				break ;
		}
	}
}

//////////////////

void	fact_instructions(t_list **parent)
{
	//print_instructions(*parent);
	//printf("<------->\n");
	pre_remove_useless_pushswap(parent);
	remove_useless_pushswap(parent);
	pre_remove_useless_push(parent);
	remove_useless_push(*parent);
	remove_useless_pushback(parent);
	add_rotation1(parent);
	add_rotation2(parent);
}
