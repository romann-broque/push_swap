/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:34:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 14:31:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define EMPTY_STRING ""
# define NULL_DEF "(null)"
# define NIL_DEF "(nil)"
# define SPACE_PAT " "
# define END_CHAR '\0'
# define PLUS_SIGN "+"
# define MINUS_SIGN "-"
# define WIDTH_UNIT " 0"
# define HEX "0123456789abcdef"
# define DEC "0123456789"
# define PREFIX_HEX "0x"
# define OPTION_CHAR "%"
# define PRECISION_CHAR "."
# define OPTIONS "cs%diuxXp"
# define NBOF_OPTIONS 9
# define UNSET_PRECISION -1

# define FLAGS " +#-0"
# define NBOF_FLAGS 4
# define NO_FLAG 0x01
# define SPACE_FLAG 0x02
# define PLUS_FLAG 0x04
# define PREFIX_FLAG 0x08
# define MINUS_FLAG 0x10
# define ZERO_FLAG 0x20

# define NO_TYPE 0x0000
# define CHAR_TYPE 0x0007
# define PERCENTAGE_TYPE 0x0004
# define CHARACTER_TYPE 0x0001
# define NB_TYPE 0x01F8
# define SIGNED_TYPE 0x0018
# define UNSIGNED_TYPE 0x01E0
# define HEX_TYPE 0x01C0
# define LOW_TYPE 0x0040
# define UP_TYPE 0x0080
# define ADDRESS_TYPE 0x0100

enum e_state
{
	E_STANDARD,
	E_MOD,
	E_WIDTH,
	E_PRECISION,
	E_CONV,
	E_END,
};

typedef uint16_t	t_type;
typedef uint8_t		t_flag;

typedef struct s_arg
{
	va_list	aptr;
	size_t	size;
	t_type	type;
	t_flag	flags;
	size_t	width;
	ssize_t	precision;
}				t_arg;

typedef struct s_output
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	index;
	size_t	total_size;
	char	*final_str;
}				t_output;

typedef struct s_machine
{
	const char		*input;
	t_output		*output;
	t_arg			*arg;
	int				fd;
	enum e_state	state;
}				t_machine;

// ft_getprintf

char		*ft_getprintf(const char *str, ...);

// ft_vdprintf

int			ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_dprintf

int			ft_dprintf(int fd, const char *str, ...);

// ft_printf

int			ft_printf(const char *str, ...);

// machine_struct

t_arg		*init_arg(t_type type, va_list aptr);
t_machine	*init_machine(const char *str, va_list aptr, int fd);
void		free_machine(t_machine *machine);

//states_utils

char		*fill_unknown(t_machine *machine);
void		fill_invalid_precision(t_machine *machine);

// converters

size_t		apply_converter(t_machine *machine);
char		*character(t_arg *arg);
char		*string(t_arg *arg);
char		*percentage(t_arg *arg);
char		*integer_d(int nb);
char		*integer_i(int nb);
char		*u_integer(unsigned long nb);
char		*low_hex(unsigned int nb);
char		*up_hex(unsigned int nb);
char		*address(void *address);

// states

size_t		conv_state(t_machine *machine);
size_t		mod_state(t_machine *machine);
size_t		width_state(t_machine *machine);
size_t		precision_state(t_machine *machine);
size_t		standard_state(t_machine *machine);

// converters/type

void		add_sign(int nb, char **output, t_arg *arg);
void		add_beginning(int nb, char **output, t_arg *arg);
char		*char_type(t_arg *arg);
char		*nb_type(t_arg *arg);
char		*signed_type(t_arg *arg);
char		*unsigned_type(t_arg *arg);
char		*hex_type(t_arg *arg, unsigned long nb);

// flags

void		remove_flag(t_flag *flags, t_flag removing_flag);
void		add_flag(t_flag *flags, t_flag removing_flag);
size_t		get_index_from_type(t_type type, t_type mask);
void		get_flag(t_flag *flags, const ssize_t flag_index);

// precision

char		*get_precision(ssize_t precision, char *string);
size_t		get_precision_size(const char *input, const t_arg *arg);

// get_size

void		get_widthsize(t_machine *machine, ssize_t option_index);

// tocase_str

char		*toupper_str(char *str);
char		*tolower_str(char *str);

// itoa_base

size_t		get_nbsize(unsigned long nb, const size_t len_base);
char		*itoa_base(const unsigned long nb, const char *base);

// utils

size_t		reduce_size(size_t width, size_t size);
ssize_t		get_index(const char *str, const char c);
char		*to_string(const char c);

// strings

size_t		ft_strlen_sec(const char *str);
char		*strset(int c, size_t n);
char		*ft_strndup(const char *str, const size_t size);
char		*add_str(char *s1, const char *s2, const size_t n);
char		*add_strn(char *s1, const size_t n1,
				const char *s2, const size_t n2);

// cpy_data

size_t		get_output_size(const char *string, const t_arg *arg);
void		cpy_data(t_output *output, void *data, size_t n);
void		cpy_to_buffer(t_machine *machine, char *string);
void		add_width(char **output, t_arg *arg);
void		prefix_add(char *prefix, char **string);

#endif
