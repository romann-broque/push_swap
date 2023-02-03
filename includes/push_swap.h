/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:29:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/03 16:55:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "libft.h"

//////////////////
/// STRUCTURES ///
//////////////////

typedef struct s_stack
{
	int		nb;
	size_t	rank;
}				t_stack;

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

// rank_sort.c

void	rank_sort(t_dualstack *dual);

// tree_sort.c

void	tree_sort(t_dualstack *dual, t_tree *root);

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

void	fact_instructions(t_list **parent);

// dualstack_utils.c

void	init_dualstack(t_dualstack *dual, t_stack *numbers, const size_t size);
void	free_dualstack(t_dualstack *dual);

// LIST //

// gen_list.c

t_stack	*get_numbers(char **arg, const size_t count);
t_list	*gen_list(t_stack *numbers, const size_t count);

// list_utils.c

void	ft_lstremove(t_list **head, void (*free_fct)(void *));
void	ft_contadd_back(t_list **lst, void *content);
void	ft_lstprint(const t_list *root);

// STACK //

// set_rank_stack.c

void	set_rank_stack(t_tree *root, t_list *stack);

// stack_utils.c

int		get_disp(const t_stack *element1, const t_stack *element2);
bool	isin_stack(t_list *stack, const int nb);
float	get_average_disp(t_list *stack);

// get_data.c

int		get_nb_from_index(t_list *stack, const size_t index);
size_t	get_index_from_nb(t_list *stack, const int nb);
size_t	get_next_index_from_nb(t_list *stack, const int nb);

#endif
