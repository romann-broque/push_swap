/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:19:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 17:43:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

int	main(void)
{
	static int	(*tester[])(void) = {
		parser_test,
	//	pixel_test,
		NULL
	};
	int			ret_val;
	size_t		i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	display_title(TEST_TITLE);
	while (tester[i] != NULL)
	{
		if (tester[i]() == EXIT_FAILURE)
			ret_val = EXIT_FAILURE;
		++i;
	}
	return (ret_val);
}
