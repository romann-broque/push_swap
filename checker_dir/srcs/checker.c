/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:54:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/05 22:26:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(char **numbers)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (are_nb_valid(numbers) == true)
		ret_val = EXIT_SUCCESS;
	return (ret_val);
	// {
	// 	ret_val = is_stack_sorted(numbers);
	// }
	// return (ret_val);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_SUCCESS;
	if (ac > 1)
		ret_val = checker(av + 1);
	return (ret_val);
}
