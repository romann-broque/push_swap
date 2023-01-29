/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:32:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:34:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	swap_test1(const size_t nb)
{
	int			in_nb[] = {1, 2};
	int			out_nb[] = {2, 1};
	size_t		size = 2;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	swap(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	swap_test2(const size_t nb)
{
	int			in_nb[] = {1};
	int			out_nb[] = {1};
	size_t		size = 1;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	swap(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	swap_test3(const size_t nb)
{
	size_t		size = 0;
	int			ret_val;
	t_list		*stack;

	stack = NULL;
	swap(stack);
	ret_val = is_lst_expected(stack, NULL, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

static int	swap_test4(const size_t nb)
{
	int			in_nb[] = {1, 5, 6, 8, 11, -1};
	int			out_nb[] = {5, 1, 6, 8, 11, -1};
	size_t		size = 6;
	int			ret_val;
	t_list		*stack;

	stack = gen_list(in_nb, size);
	swap(stack);
	ret_val = is_lst_expected(stack, out_nb, size);
	ft_lstclear(&stack, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

int	swap_test(void)
{
	static int	(*tests[])(const size_t) = {
		swap_test1,
		swap_test2,
		swap_test3,
		swap_test4,
		NULL};

	display_title(SWAP_TEST_TITLE);
	return (test_sequence(tests));
}
