/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:28:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 17:06:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

int	check_result(const size_t test_index, const int curr_res, const int exp_res)
{
	printf("Test%zu: ", test_index + 1);
	if (curr_res == exp_res)
	{
		printf(GREEN_PRINT "OK\n" RESET);
		return (EXIT_SUCCESS);
	}
	printf(RED_PRINT "KO\n" RESET);
	return (EXIT_FAILURE);
}

int	test_sequence(int (*tests[])(const size_t))
{
	int			ret_val;
	size_t		i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (tests[i] != NULL)
	{
		if (tests[i](i) == EXIT_FAILURE)
			ret_val = EXIT_FAILURE;
		++i;
	}
	return (ret_val);
}

int	is_lst_expected(t_list *lst, int out_nb[], const size_t size)
{
	size_t	i;
	int		ret_val = KO;

	i = 0;
	while (lst != NULL && *((int *)(lst->content)) == out_nb[i])
	{
		lst = lst->next;
		++i;
	}
	if (i == size)
		ret_val = OK;
	return (ret_val);
}


void	display_title(const char *title)
{
	printf("%s", title);
}
