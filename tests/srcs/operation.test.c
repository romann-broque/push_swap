/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:40:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/29 00:41:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

int	operation_test(void)
{
	static int	(*tests[])(const size_t) = {
		NULL};

	display_title(OPERATION_TEST_TITLE);
	return (test_sequence(tests));

}
