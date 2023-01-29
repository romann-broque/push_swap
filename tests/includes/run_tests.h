/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 00:41:45 by rbroque          ###   ########.fr       */
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
# define OPERATION_TEST_TITLE "\n<====== OPERATIONS ======>\n"

/////////////////////////////////
//// <----- FUNCTIONS -----> ////
/////////////////////////////////

/// UTILS ///

int		check_result(const size_t test_index, const int curr_res, const int exp_res);
int		test_sequence(int (*tests[])(const size_t));
void	display_title(const char *title);

// OPERATIONS

int		operation_test(void);

#endif
