/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:08:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 11:32:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstinsert(t_list **head, void *content)
{
	t_list	*next;
	t_list	*new;

	new = ft_lstnew(content);
	if (new != NULL)
	{
		if (*head == NULL)
			*head = new;
		else
		{
			next = (*head)->next;
			(*head)->next = new;
			new->next = next;
		}
	}
}

void	ft_lstremove(t_list **head, void (*free_fct)(void *))
{
	t_list	*tmp;

	if (*head != NULL)
	{
		if ((*head)->next != NULL)
		{
			tmp = (*head)->next->next;
			ft_lstdelone((*head)->next, free_fct);
			(*head)->next = tmp;
		}
		else
		{
			ft_lstdelone(*head, free_fct);
			*head = NULL;
		}
	}
}

void	ft_contadd_back(t_list **lst, void *content)
{
	ft_lstadd_back(lst, ft_lstnew(content));
}

void	ft_lstprint(const t_list *root)
{
	while (root != NULL)
	{
		ft_printf("(%d)-", *((int *)(root->content)));
		root = root->next;
	}
	ft_printf("NULL\n");
}
