/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:29:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:37:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "libft.h"

//////////////////
/// STRUCTURES ///
//////////////////

typedef struct s_dualstack
{
	t_list	*a;
	t_list	*b;
}				t_dualstack;

//////////////////
/// FUNCTIONS ///
/////////////////

// OPERATIONS //

// swap.c

void	swap(t_list *stack);
void	sa(t_dualstack	*dual);
void	sb(t_dualstack	*dual);

// push.c

void	push(t_list **stack_src, t_list **stack_dest);
void	pa(t_dualstack *dual);
void	pb(t_dualstack *dual);

// list_utils.c

int		*get_numbers(char **arg, const size_t count);
t_list	*gen_list(int *numbers, const size_t count);
void	ft_lstprint(const t_list *root);

#endif
