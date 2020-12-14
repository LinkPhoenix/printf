/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:54:22 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/14 12:06:44 by emlecerf         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buffer	buffer = {.i = 0};
	int i;
	int u_i;
	char c;
	char *str;
	int j;
	int nbr;
	unsigned long ptr;

	va_start(ap, format);
	j = -1;
	while (format[++j])
	{
		if (format[j] == '%' && format[j + 1] == '%')
		{
			write(1, "%", 1);
			j += 2;
		}
		if (format[j] == '%' && (format[j + 1] == 'd' || format[j + 1] == 'i'))
		{
			i = va_arg(ap, int);
		 	ft_putnbr(i);
		 	j += 2;
		}
		if (format[j] == '%' && (format[j + 1] == 'u'))
		{
			i = va_arg(ap, unsigned int);
				print_base(i, "0123456789", 10);
			j += 2;
		}
		 if (format[j] == '%' && format[j + 1] == 'c')
		 {
		 	c = (char)va_arg(ap, int);
		 	write (1, &c, 1);
		 	j += 2;
		 }
		 if (format[j] == '%' && format[j + 1] == 's')
		 {
		 	str = (char*)va_arg(ap, char*);
		 	ft_putstr(str);
		 	j += 2;
		 }
		if (format[j] == '%' && (format[j + 1] == 'X' || format[j + 1] == 'x'))
		{
			nbr = va_arg(ap, int);
			if (format[j + 1] == 'X')
				print_base(nbr, "0123456789ABCDEF", 16);
			else if (format[j + 1] == 'x')
				print_base(nbr, "0123456789abcdef", 16);
			j += 2;
		}
		if (format[j] == '%' && format[j + 1] == 'p')
		{
			ptr = va_arg(ap, unsigned long);
			write (1, "0x", 2);
			print_base(ptr, "0123456789abcdef", 16);
			j += 2;
		}
		if (format[j] == '%' && format[j + 1] == 'o')
		{
			u_i = va_arg(ap, unsigned int);
			print_base(u_i, "01234567", 8);
			j += 2;
		}
		write(1, &format[j], 1);
	}
	va_end(ap);
	return (j - 1);
}