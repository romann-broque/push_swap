/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:02:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 22:18:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	is_stack_sorted_test1(const size_t nb)
{
	int			in_nb[] = {1, 5, 6, 8, 11, -1};
	size_t		size = 6;
	int			expect_ret = KO;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

static int	is_stack_sorted_test2(const size_t nb)
{
	int			in_nb[] = {-1, 1, 5, 6, 8, 11};
	size_t		size = 6;
	int			expect_ret = OK;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

static int	is_stack_sorted_test3(const size_t nb)
{
	int			in_nb[] = {-1, 1};
	size_t		size = 2;
	int			expect_ret = OK;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

static int	is_stack_sorted_test4(const size_t nb)
{
	int			in_nb[] = {-1};
	size_t		size = 1;
	int			expect_ret = OK;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

static int	is_stack_sorted_test5(const size_t nb)
{
	int			in_nb[] = {0, -12};
	size_t		size = 2;
	int			expect_ret = KO;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

static int	is_stack_sorted_test6(const size_t nb)
{
	int			expect_ret = OK;
	int			ret_val;
	t_list		*stack;

	stack = NULL;
	ret_val = !(is_stack_sorted(stack));
	ft_lstclear(&stack, NULL);
	return (check_result(nb, ret_val, expect_ret));
}

int	is_stack_sorted_test(void)
{
	static int	(*tests[])(const size_t) = {
		is_stack_sorted_test1,
		is_stack_sorted_test2,
		is_stack_sorted_test3,
		is_stack_sorted_test4,
		is_stack_sorted_test5,
		is_stack_sorted_test6,
		NULL};

	display_title(IS_STACK_SORTED_TEST_TITLE);
	return (test_sequence(tests));
}
