/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:15:57 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/13 21:52:26 by emlecerf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void    ft_putnbr(int nb)
{
	long    nbr;
	long    i;
	char    nbr_char[11];

	nbr = nb;
	i = 10;
	nbr_char[10] = 48;
	if (nb == -2147483648)
	{
		nbr_char[i--] = '8';
		nb /= 10;
	}
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nbr_char[i--] = nb % 10 + 48;
		nb /= 10;
	}
	if (nbr < 0)
		nbr_char[i] = '-';
	else if (nbr != 0)
		i++;
	write(1, &nbr_char[i], 11 - i);
}

void	ft_putstr(char *str)
{
	while(*str)
		write (1, str++, 1);
}

void		print_binary(unsigned int nbr)
{
	while (nbr)
	{
		if (nbr & 1)
			printf("1");
		else
			printf("0");

		nbr >>= 1;
	}
	printf("\n");
}

void		print_base(unsigned long nbr, char *base, int len_base)
{
	if (nbr / len_base)
		print_base((nbr / len_base), base, len_base);
  	write(1, &base[nbr % len_base], 1);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
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

int		main(int argc, char **argv)
{
	(void)argc;
	int decimal =  15;
	char character = 'c';
	char *string = "je suis ici\n";
	int n = 129;
	unsigned long nbr_slong = 0042;

	printf("printf \t| decimal \t| %%0o | %010d\n", nbr_slong);
	printf("ft_printf \t| decimal \t| %%o | %o\n", nbr_slong);
	ft_printf("printf \t\t| decimal \t\t| %%o | %o\n", nbr_slong);
	ft_printf("ft_printf \t| int \t\t| %%i | %i\n", decimal);
	printf("printf \t\t| int \t\t\t| %%i | %i\n", decimal);
	ft_printf("ft_printf \t| decimal \t| %%d | %d\n", decimal);
	printf("printf \t\t| decimal \t\t| %%d | %d\n", decimal);
	ft_printf("ft_printf \t| decimal \t| %%d | %d\n", decimal);
	printf("printf \t\t| decimal \t\t| %%d | %d\n", decimal);
	ft_printf("charactere \t\t| %%c | %c\n", character);
	ft_printf("string \t\t\t| %%s | %s\n", string);
	ft_printf("HEXA \t\t| %%X | %X\n", decimal);
	ft_printf("hexa \t\t\t| %%x | %x\n", decimal);
	print_binary(decimal);
	// ft_printf("ui \t\t\t| %% ui \t| %ui\n", ui);
	// unsigned int ui = -2;

	// printf("ui = %u", ui);
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("SCHAR_MIN : %d\n", SCHAR_MIN);
	printf("SCHAR_MAX : %d\n", SCHAR_MAX);
	printf("USCHAR_MAX : %d\n", UCHAR_MAX);
	printf("SHRT_MIN : %d\n", SHRT_MIN);
	printf("SHRT_MAX : %d\n", SHRT_MAX);
	printf("INT_MIN : %i\n", INT_MIN);
	printf("INT_MAX : %i\n", INT_MAX);
	printf("UINT_MAX : %ui\n", UINT_MAX);
	printf("LONG_MIN : %ld\n", LONG_MIN);
	printf("LONG_MAX : %ld\n", LONG_MAX);
	printf("ULONG_MAX : %lu\n", ULONG_MAX);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("ULLONG_MAX : %llu\n", ULLONG_MAX);
	printf("CHAR_BIT : %d\n", CHAR_BIT);
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("MB_LEN_MAX : %i\n", MB_LEN_MAX);

	printf("Source file names : %s\nLine Nmber : %i\nDate : %s\nCompilation Time : %s\n",__FILE__, __LINE__, __DATE__, __TIME__);
	printf("STD : %d\n", __STDC__);
	printf("STD Version : %ld\n", __STDC_VERSION__);

	return 0;
}
