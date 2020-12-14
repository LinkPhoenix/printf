/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:56:50 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/14 12:05:47 by emlecerf         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_buffer
{
	char	buffer[100];
	int		i;
	int		size;
}				t_buffer;

typedef struct	s_directive
{
	char	sharp;
	char 	zero;
	char	minus;
	char	space;
	char	plus;
	int		width;
	// int size;
	char	precision_b;
	int 	precision;
}				t_directive;

/*typedef struct	s_directive_b
{
	char	flags;
	int		width;
	// int size;
	int		precision;
}				t_directive_b;*/

void    	ft_putnbr(int nb);
void		ft_putstr(char *str);
void		print_base(unsigned long nbr, char *base, int len_base);
int	ft_printf(const char *format, ...);

#endif