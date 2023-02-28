/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:33:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:52:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "push_swap.h"

// PARSER //

// parsing_nb.c

bool	are_nb_valid(char **numbers);

// get_args.c

char	**get_arguments(char **arg);

// parser_utils.c

size_t	get_strs_size(char **strs);
void	add_strs(char ***dest, char **src, const size_t size2);
void	cpy_arg(char ***dest, char **arg);

#endif
