/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:36:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:52:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POST_PROCESS_H
# define POST_PROCESS_H

# include "push_swap.h"

// POST_PROCESS //

// post_process

void	post_process(t_list **parent);

// rm_useless_push.c

void	pre_remove_useless_push(t_list **parent);
void	remove_useless_push(t_list **parent);

// rm_useless_pushswap.c

void	pre_remove_useless_pushswap(t_list **parent);
void	remove_useless_pushswap(t_list **parent);

// rotate_fact.c

void	rotate_fact1(t_list **parent);
void	rotate_fact2(t_list **parent);

#endif
