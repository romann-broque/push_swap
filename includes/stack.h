/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:32:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:53:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

// STACK //

// set_rank_stack.c

void	set_rank_stack(t_tree *root, t_list *stack);

// stack_utils.c

int		get_disp(const t_stack *element1, const t_stack *element2);
bool	isin_stack(t_list *stack, const int nb);
float	get_average_disp(t_list *stack);
int		get_nb(t_list *elem_stack);
size_t	get_rank(t_list *elem_stack);


#endif
