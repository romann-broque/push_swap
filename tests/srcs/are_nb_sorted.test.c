/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_nb_sorted.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:23:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 23:30:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	are_nb_sorted_test1(const size_t nb)
{
	int			nb1 = 1;
	int			nb2 = 2;
	int			expect_ret = OK;
	int			ret_val;
	t_list		*n1 = ft_lstnew(&nb1);
	t_list		*n2 = ft_lstnew(&nb2);

	ret_val = !(are_nb_sorted(n1, n2));
	free(n1);
	free(n2);
	return (check_result(nb, ret_val, expect_ret));
}

static int	are_nb_sorted_test2(const size_t nb)
{
	int			nb1 = 1;
	int			nb2 = -1;
	int			expect_ret = KO;
	int			ret_val;
	t_list		*n1 = ft_lstnew(&nb1);
	t_list		*n2 = ft_lstnew(&nb2);

	ret_val = !(are_nb_sorted(n1, n2));
	free(n1);
	free(n2);
	return (check_result(nb, ret_val, expect_ret));
}

static int	are_nb_sorted_test3(const size_t nb)
{
	int			nb1 = 1;
	int			expect_ret = KO;
	int			ret_val;
	t_list		*n1 = ft_lstnew(&nb1);

	ret_val = !(are_nb_sorted(n1, NULL));
	free(n1);
	return (check_result(nb, ret_val, expect_ret));
}

int	are_nb_sorted_test(void)
{
	static int	(*tests[])(const size_t) = {
		are_nb_sorted_test1,
		are_nb_sorted_test2,
		are_nb_sorted_test3,
		NULL};

	display_title(ARE_NB_SORTED_TEST_TITLE);
	return (test_sequence(tests));
}
