/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:38:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 17:07:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_TREE_H
# define BIN_TREE_H

# include "push_swap.h"

// BIN_TREE //

// tree_utils.c

t_tree	*create_root(const int nb);
t_tree	*create_tree(t_list *stack);
void	display_tree(t_tree *root);
void	clear_tree(t_tree *tree);

// infix.c

void	infix_sort(t_dualstack *dual, t_tree *root);
void	infix_sort_rev(t_dualstack *dual, t_tree *root);

#endif
