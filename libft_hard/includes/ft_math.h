/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:15:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/02/26 12:50:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdio.h>
# define EULER_CONST 2.718281828459045235
# define TAYLOR_ITERATIONS 20

unsigned long	get_abs(int n);
int				get_max(const int n1, const int n2);
size_t			get_max_sz(const size_t n1, const size_t n2);
double			ft_log(double x);

#endif
