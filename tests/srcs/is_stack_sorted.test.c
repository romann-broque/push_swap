/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:48:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/01 16:57:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	is_stack_sorted_sub(char *arg, const size_t nb, const size_t size, int expect_ret)
{
	char		**split_arg;
	int			ret_val;
	t_stack		*stack;
	t_list		*lst;
	t_tree		*tree;

	split_arg = ft_split(arg, ' ');
	stack = get_numbers(split_arg, size);
	lst = gen_list(stack, size);

	tree = create_tree(lst);
	set_index_stack(tree, lst);
	ret_val = !(is_stack_sorted(lst));
	free_strs(split_arg);
	ft_lstclear(&lst, NULL);
	clear_tree(tree);
	return (check_result(nb, ret_val, expect_ret));

}

static int	is_stack_sorted_test1(const size_t nb)
{
	char	*arg = "1 5 6 8 11 -1";

	return (is_stack_sorted_sub(arg, nb, 6, OK));
}

static int	is_stack_sorted_test2(const size_t nb)
{
	char	*arg = "1 5 6";

	return (is_stack_sorted_sub(arg, nb, 3, OK));
}

static int	is_stack_sorted_test3(const size_t nb)
{
	char	*arg = "1 5 -1";

	return (is_stack_sorted_sub(arg, nb, 3, OK));
}

static int	is_stack_sorted_test4(const size_t nb)
{
	char	*arg = "1 5 10 0 3";

	return (is_stack_sorted_sub(arg, nb, 5, KO));
}

static int	is_stack_sorted_test5(const size_t nb)
{
	char	*arg = "1 5 4";

	return (is_stack_sorted_sub(arg, nb, 3, KO));
}

static int	is_stack_sorted_test6(const size_t nb)
{
	char	*arg = "5 1 4";

	return (is_stack_sorted_sub(arg, nb, 3, OK));
}

static int	is_stack_sorted_test7(const size_t nb)
{
	char	*arg = "5 4 1";

	return (is_stack_sorted_sub(arg, nb, 3, KO));
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
		is_stack_sorted_test7,
		NULL};

	display_title(IS_STACK_SORTED_TEST_TITLE);
	return (test_sequence(tests));
}
