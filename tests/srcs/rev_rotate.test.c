/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:07:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 21:55:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	rev_rotate_test1(const size_t nb)
{
	int			in_nb[] = {1, 5, 6, 8, 11, -1};
	int			out_nb[] = {-1, 1, 5, 6, 8, 11};
	size_t		size = 6;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rev_rotate(&stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rev_rotate_test2(const size_t nb)
{
	int			in_nb[] = {1, 5};
	int			out_nb[] = {5, 1};
	size_t		size = 2;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rev_rotate(&stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rev_rotate_test3(const size_t nb)
{
	int			in_nb[] = {1};
	int			out_nb[] = {1};
	size_t		size = 1;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rev_rotate(&stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rev_rotate_test4(const size_t nb)
{
	size_t		size = 0;
	int			ret_val;
	t_list		*stack;

	stack = NULL;
	rev_rotate(&stack);
	ret_val = is_lst_expected(stack, NULL, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

int	rev_rotate_test(void)
{
	static int	(*tests[])(const size_t) = {
		rev_rotate_test1,
		rev_rotate_test2,
		rev_rotate_test3,
		rev_rotate_test4,
		NULL};

	display_title(REV_ROTATE_TEST_TITLE);
	return (test_sequence(tests));
}
