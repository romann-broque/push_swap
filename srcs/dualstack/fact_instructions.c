/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/14 15:42:05 by rbroque          ###   ########.fr       */
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
			ft_lstremove(&((*parent)->next), NULL);
			ft_lstremove(&((*parent)->next), NULL);
			(*parent)->next->content = "sa";
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

//////////////////

// static t_list	*ft_lstget(t_list *head, const size_t index)
// {
// 	size_t	i;

// 	i = 0;
// 	while (head != NULL && i < index)
// 	{
// 		head = head->next;
// 		++i;
// 	}
// 	return (head);
// }

// static size_t	get_index_from_str(t_list *parent, const char *str)
// {
// 	size_t	index;

// 	index = 0;
// 	while (parent != NULL && ft_strcmp(parent->content, str) != 0)
// 	{
// 		++index;
// 		parent = parent->next;
// 	}
// 	return (index);
// }

// static size_t	count_list_occurence(t_list *parent, const char *str)
// {
// 	size_t	count;

// 	count = 0;
// 	while (parent != NULL)
// 	{
// 		if (ft_strcmp(parent->content, str) == 0)
// 			++count;
// 		parent = parent->next;
// 	}
// 	return (count);
// }

// static void	remove_last_pa(t_list **parent)
// {
// 	if (*parent != NULL)
// 	{
// 		ft_lstclear(&((*parent)->next), NULL);
// 		(*parent)->next = NULL;
// 	}
// }

// void	remove_useless_pushback(t_list **parent)
// {
// 	const size_t	count_pb = count_list_occurence(*parent, "pb");
// 	const size_t	index_pa = get_index_from_str(*parent, "pa");
// 	t_list			*begin_pa;

// 	if ((index_pa + count_pb == 0) || (count_pb == 1 && index_pa == 1))
// 		ft_lstclear(parent, NULL);
// 	else
// 	{
// 		begin_pa = ft_lstget(*parent, index_pa + count_pb - 1);
// 		remove_last_pa(&begin_pa);
// 	}
// }

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

void	fact_instructions(t_list **parent)
{
	//print_instructions(*parent);
	//printf("<------->\n");
	//remove_useless_pushback(parent);
	// pre_remove_useless_pushswap(parent);
	// remove_useless_pushswap(parent);
	pre_remove_useless_push(parent);
	remove_useless_push(parent);
	rotate_fact1(parent);
	fact_push_rotate(parent);
	rotate_fact2(parent);
}
