/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:44:44 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:52:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_DATA_H
# define GET_DATA_H

# include "push_swap.h"

// GET_DATA //

// get_index.c

ssize_t	get_index_from_nb(t_list *stack, const int nb);
ssize_t	get_index_from_rank(t_list *stack, const size_t rank);
ssize_t	get_next_index_from_nb(t_list *stack, const int nb);
ssize_t	get_prev_index_from_nb(t_list *stack, const int nb);
ssize_t	get_next_index_from_index(t_list *stack_src, t_list *stack_dest,
			const size_t index);

// get_rank.c

ssize_t	get_rank_from_nb(t_list *stack, const int nb);
size_t	get_rank_from_index(t_list *stack, size_t index);

// get_nb.c

long	get_nb_from_index(t_list *stack, const size_t index);
long	get_nb_from_rank(t_list *stack, const size_t rank);

#endif
