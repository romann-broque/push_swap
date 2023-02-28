/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:48:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/22 14:48:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lst_fill(t_list *lst, void *(*f)(void *))
{
	t_list	*fill;

	if (f == NULL)
		fill = ft_lstnew(lst->content);
	else
		fill = ft_lstnew(f(lst->content));
	return (fill);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*curr;

	if (lst == NULL)
		return (NULL);
	new_head = lst_fill(lst, f);
	curr = new_head;
	while (lst->next != NULL && curr != NULL)
	{
		curr->next = lst_fill(lst->next, f);
		if (curr->next == NULL)
		{
			ft_lstclear(&new_head, del);
			break ;
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (new_head);
}
