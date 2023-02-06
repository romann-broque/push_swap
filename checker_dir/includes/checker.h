/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:24:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/06 14:50:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

// parsing_nb.c

bool	are_nb_valid(const char **numbers);

// read_instructions.c

char	**get_instructions(void);

// OPERATIONS

// swap_fct.c

void	sa_fct(t_dualstack *dual);
void	sb_fct(t_dualstack *dual);
void	ss_fct(t_dualstack *dual);

// rotate_fct.c

void	ra_fct(t_dualstack *dual);
void	rb_fct(t_dualstack *dual);
void	rr_fct(t_dualstack *dual);

// push_fct.c

void	pa_fct(t_dualstack *dual);
void	pb_fct(t_dualstack *dual);

// rev_rotate_fct.c

void	rra_fct(t_dualstack *dual);
void	rrb_fct(t_dualstack *dual);
void	rrr_fct(t_dualstack *dual);

#endif
