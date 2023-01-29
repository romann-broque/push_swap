/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 23:25:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_TESTS_H
# define RUN_TESTS_H

# include "../includes/push_swap.h"

///////////////////////////////
//// <----- DEFINES -----> ////
///////////////////////////////

# define RESET "\033[0m"
# define RED_PRINT "\033[1m\033[31m"
# define GREEN_PRINT "\033[32m"
# define OK EXIT_SUCCESS
# define KO EXIT_FAILURE

///////////
// TITLE //
///////////

# define TEST_TITLE "\n<====== TESTS ======>\n"
# define SWAP_TEST_TITLE "\n<====== SWAP ======>\n\n"
# define PUSH_TEST_TITLE "\n<====== PUSH ======>\n\n"
# define ROTATE_TEST_TITLE "\n<====== ROTATE ======>\n\n"
# define REV_ROTATE_TEST_TITLE "\n<====== REV_ROTATE ======>\n\n"
# define IS_STACK_SORTED_TEST_TITLE "\n<====== IS_STACK_SORTED ======>\n\n"
# define ARE_NB_SORTED_TEST_TITLE "\n<====== ARE_NB_SORTED ======>\n\n"

/////////////////////////////////
//// <----- FUNCTIONS -----> ////
/////////////////////////////////

/// UTILS ///

int		is_lst_expected(t_list *lst, int out_nb[], const size_t size);
int		check_result(const size_t test_index, const int curr_res, const int exp_res);
int		test_sequence(int (*tests[])(const size_t));
void	display_title(const char *title);

// OPERATIONS

int		swap_test(void);
int		push_test(void);
int		rotate_test(void);
int		rev_rotate_test(void);
int		is_stack_sorted_test(void);
int		are_nb_sorted_test(void);

#endif
