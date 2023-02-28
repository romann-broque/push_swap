/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:43:44 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:52:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "push_swap.h"

// LIST //

// gen_list.c

t_stack	*get_numbers(char **arg, const size_t count);
t_list	*gen_list(t_stack *numbers, const size_t count);

// list_utils.c

t_list	*dup_list(t_list *list);
void	ft_lstremove(t_list **head, void (*free_fct)(void *));
void	ft_contadd_back(t_list **lst, void *content);
void	ft_lstprint(const t_list *root);

#endif
