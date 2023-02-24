/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:37:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/24 17:06:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	post_process(t_list **parent)
{
	remove_useless_push(parent);
	rotate_fact1(parent);
	rotate_fact2(parent);
	remove_useless_push(parent);
	pre_remove_useless_push(parent);
	remove_useless_pushswap(parent);
	pre_remove_useless_pushswap(parent);
}
