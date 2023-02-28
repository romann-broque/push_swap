/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:31:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

// OPERATIONS //

// swap.c

void	swap(t_list *stack);
void	sa(t_dualstack	*dual);
void	sb(t_dualstack	*dual);
void	ss(t_dualstack	*dual);

// push.c

void	push(t_list **stack_src, t_list **stack_dest);
void	pa(t_dualstack *dual);
void	pb(t_dualstack *dual);

// rotate.c

void	rotate(t_list *stack);
void	ra(t_dualstack	*dual);
void	rb(t_dualstack	*dual);
void	rr(t_dualstack *dual);

// rev_rotate.c

void	rev_rotate(t_list **stack);
void	rra(t_dualstack *dual);
void	rrb(t_dualstack *dual);
void	rrr(t_dualstack *dual);

#endif
