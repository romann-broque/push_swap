/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:31:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/23 11:26:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_tests.h"

static int	is_parsing_valid__test1(const size_t test_index)
{
	const char	*path_file = PARSER_PATH1;
	const int	exp_result = OK;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test2(const size_t test_index)
{
	const char	*path_file = PARSER_PATH2;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test3(const size_t test_index)
{
	const char	*path_file = PARSER_PATH3;
	const int	exp_result = OK;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test4(const size_t test_index)
{
	const char	*path_file = PARSER_PATH4;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test5(const size_t test_index)
{
	const char	*path_file = PARSER_PATH5;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test6(const size_t test_index)
{
	const char	*path_file = PARSER_PATH6;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test7(const size_t test_index)
{
	const char	*path_file = PARSER_PATH7;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test8(const size_t test_index)
{
	const char	*path_file = PARSER_PATH8;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test9(const size_t test_index)
{
	const char	*path_file = PARSER_PATH9;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test10(const size_t test_index)
{
	const char	*path_file = PARSER_PATH10;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test11(const size_t test_index)
{
	const char	*path_file = PARSER_PATH11;
	const int	exp_result = KO;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test12(const size_t test_index)
{
	const char	*path_file = PARSER_PATH12;
	const int	exp_result = OK;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

static int	is_parsing_valid__test13(const size_t test_index)
{
	const char	*path_file = PARSER_PATH13;
	const int	exp_result = OK;
	char		***parsing;
	int			ret_val;

	parse(&parsing, path_file);
	ret_val = is_parsing_valid(parsing);
	free_parsing(&parsing);
	return (check_result(test_index, !ret_val, exp_result));
}

int	parser_test(void)
{
	static int	(*tests[])(const size_t) = {
		is_parsing_valid__test1,
		is_parsing_valid__test2,
		is_parsing_valid__test3,
		is_parsing_valid__test4,
		is_parsing_valid__test5,
		is_parsing_valid__test6,
		is_parsing_valid__test7,
		is_parsing_valid__test8,
		is_parsing_valid__test9,
		is_parsing_valid__test10,
		is_parsing_valid__test11,
		is_parsing_valid__test12,
		is_parsing_valid__test13,
		NULL};

	display_title(PARSER_TEST_TITLE);
	return (test_sequence(tests));
}
