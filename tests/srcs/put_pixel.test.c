/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 17:44:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

/*
static void	print_bits(const unsigned int nb)
{
	int	i;

	i = sizeof(nb) * 8 - 1;
	while (i >= 0)
	{
		if (i % 4 == 3)
			printf(" ");
		printf("%d", (nb >> i) & 1);
		--i;
	}
	printf("\n");
}

static void	print_data(char *str, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			print_bits(*(str + i * j));
			++j;
		}
		++i;
	}
}

static int	is_pixel_put_valid__test1(const size_t test_index)
{
	const int		exp_result = OK;
//	const size_t	x = 6;
//	const size_t	y = 5;
//	const size_t	color = WHITE;
	int				ret_val;
	char			*data_str1;
	char			*data_str2;
	t_win			window;

	ret_val = OK;
	init_window(&window, NULL);
	if (window.data.img != NULL)
	{
		data_str1 = mlx_get_data_addr(window.data.img, &window.data.bits_per_pixel, &window.data.line_length, &window.data.endian);
		//put_pixel(&window.data, x + 1, y + 1, color);
		data_str2 = mlx_get_data_addr(window.data.img, &window.data.bits_per_pixel, &window.data.line_length, &window.data.endian);
		ret_val = ft_strncmp(data_str1, data_str2, window.data.bits_per_pixel * window.data.line_length);
	}
	free_window(&window);
	return (check_result(test_index, ret_val, exp_result));
}

int	pixel_test(void)
{
	static int	(*tests[])(const size_t) = {
		is_pixel_put_valid__test1,
		NULL};

	display_title(PIXEL_TEST_TITLE);
	return (test_sequence(tests));
}

*/