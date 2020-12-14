/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:55:10 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/14 12:07:19 by emlecerf         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void		print_binary(unsigned int nbr)
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

int		main(int argc, char **argv)
{
	(void)argc;
	int decimal =  15;
	char character = 'c';
	char *string = "je suis ici\n";
	int n = 129;
	unsigned long nbr_slong = 42;

	printf("printf \t| decimal \t| %%0o | %020d bonjour\n", nbr_slong);
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

