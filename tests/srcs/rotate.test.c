/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:12:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 18:20:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	rotate_test1(const size_t nb)
{
	int			in_nb[] = {1, 5, 6, 8, 11, -1};
	int			out_nb[] = {5, 6, 8, 11, -1, 1};
	size_t		size = 6;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rotate(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rotate_test2(const size_t nb)
{
	int			in_nb[] = {1};
	int			out_nb[] = {1};
	size_t		size = 1;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rotate(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rotate_test3(const size_t nb)
{
	int			in_nb[] = {1, 2};
	int			out_nb[] = {2, 1};
	size_t		size = 2;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	rotate(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	rotate_test4(const size_t nb)
{
	int			ret_val;
	t_list		*stack;

	stack = NULL;
	rotate(stack);
	ret_val = is_lst_expected(stack, NULL, 0);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

int	rotate_test(void)
{
	static int	(*tests[])(const size_t) = {
		rotate_test1,
		rotate_test2,
		rotate_test3,
		rotate_test4,
		NULL};

	display_title(ROTATE_TEST_TITLE);
	return (test_sequence(tests));
}
