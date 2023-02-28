/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dualstack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:31:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 17:07:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUALSTACK_H
# define DUALSTACK_H

# include "push_swap.h"

// DUAL_STACK //

// cpy_dualstack.c

void	cpy_dualstack(t_dualstack *dest, t_dualstack *src);

// print_dualstack.c

void	print_dualstack(t_dualstack *dual);

// print_instructions.c

void	print_instructions(t_list *instructions);

// dualstack_utils.c

void	init_dualstack(t_dualstack *dual, t_stack *numbers, const size_t size);
void	free_dualstack(t_dualstack *dual);

#endif
