/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:40:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:34:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	push_test1(const size_t nb)
{
	int			in_nb1[] = {1, 5, 6, 8, 11, -1};
	int			out_nb1[] = {5, 6, 8, 11, -1};
	int			out_nb2[] = {1};
	size_t		in_size = 6;
	size_t		out_size_a = 5;
	size_t		out_size_b = 1;
	t_list		*stack_a;
	t_list		*stack_b;
	int			ret_val;

	stack_a = gen_list(in_nb1, in_size);
	stack_b = NULL;
	push(&stack_a, &stack_b);
	ret_val = is_lst_expected(stack_a, out_nb1, out_size_a)
				&& is_lst_expected(stack_b, out_nb2, out_size_b);
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
	check_result(nb, ret_val, OK);
	return (ret_val);
}

int	push_test(void)
{
	static int	(*tests[])(const size_t) = {
		push_test1,
		NULL};

	display_title(PUSH_TEST_TITLE);
	return (test_sequence(tests));
}
