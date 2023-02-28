/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:47:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/28 14:53:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "push_swap.h"

typedef struct s_stack
{
	int		nb;
	size_t	rank;
}				t_stack;

typedef struct s_tree
{
	int				content;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct s_dualstack
{
	t_list	*a;
	t_list	*b;
	t_list	*instructions;
	t_tree	*tree;
}				t_dualstack;

typedef struct s_sort_fct
{
	void	(*sort_fct)(t_dualstack *);
	size_t	max_size;
}				t_sort_fct;

#endif
