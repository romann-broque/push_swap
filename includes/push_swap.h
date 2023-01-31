/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:29:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/31 13:50:56 by rbroque          ###   ########.fr       */
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
	t_list	*instructions;
}				t_dualstack;

typedef struct s_tree
{
	int				content;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

//////////////////
/// FUNCTIONS ///
/////////////////

// SORT //

// is_sorted.c

bool	are_nb_sorted(t_list *n1, t_list *n2);
bool	is_stack_valid(t_list *stack);
bool	is_stack_sorted(t_list *stack);

// sort_dualstack.c

void	sort_dualstack(t_dualstack *dual);

// sort_stack.c

void	sort_stack(t_list *stack_a);

// BIN_TREE //

// tree_utils.c

t_tree	*create_tree(t_list *stack);
void	display_tree(t_tree *root);
void	clear_tree(t_tree *tree);

// OPERATIONS //

// swap.c

void	swap(t_list *stack);
void	sa(t_dualstack	*dual);
void	sb(t_dualstack	*dual);
void	ss(t_dualstack	*dual);

// push.c

void	push(t_list **stack_src, t_list **stack_dest);
void	pa(t_dualstack *dual);
void	pb(t_dualstack *dual);

// rotate.c

void	rotate(t_list *stack);
void	ra(t_dualstack	*dual);
void	rb(t_dualstack	*dual);
void	rr(t_dualstack *dual);

// rev_rotate.c

void	rev_rotate(t_list **stack);
void	rra(t_dualstack *dual);
void	rrb(t_dualstack *dual);
void	rrr(t_dualstack *dual);

// DUAL_STACK //

// print_dualstack.c

void	print_dualstack(t_dualstack *dual);

// print_instructions.c

void	print_instructions(t_list *instructions);

// fact_instructions.c

void	fact_instructions(t_list *parent);

// STACK //

// gen_list.c

int		*get_numbers(char **arg, const size_t count);
t_list	*gen_list(int *numbers, const size_t count);

// list_utils.c

void	ft_lstremove(t_list **head, void (*free_fct)(void *));
void	ft_contadd_back(t_list **lst, void *content);
void	ft_lstprint(const t_list *root);

// stack_utils.c

int	get_nb_index(t_list *stack, const int nb);

#endif
