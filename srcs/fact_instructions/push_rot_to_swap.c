/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rot_to_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:53:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/24 02:11:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_push_rot(t_list **parent)
{
	return (ft_strcmp((*parent)->content, "rra") == 0
		&& ft_strcmp((*parent)->next->content, "pb") == 0
		&& ft_strcmp((*parent)->next->next->content, "ra") == 0
		&& ft_strcmp((*parent)->next->next->next->content, "pa") == 0);
}

static void	replace_push_rot(t_list **parent)
{
	ft_lstremove(&(*parent)->next, NULL);
	ft_lstremove(parent, NULL);
	(*parent)->content = "sa";
	(*parent)->next->content = "rra";
}

void	pre_push_rot_to_swap(t_list **parent)
{
	if (ft_lstsize(*parent) == 4 && is_push_rot(parent) == true)
		replace_push_rot(parent);
}
