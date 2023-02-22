/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/21 17:04:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fact_instructions(t_list **parent)
{
	remove_useless_pushswap(parent);
	remove_useless_push(parent);
	rotate_fact1(parent);
	rotate_fact2(parent);
	pre_remove_useless_push(parent);
	remove_useless_push(parent);
	push_rot_to_swap(parent);
	pre_push_rot_to_swap(parent);
	pre_remove_useless_pushswap(parent);
}
