/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:15:57 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/12 02:45:54 by emlecerf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

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


int		ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	int j;
	
	va_start(ap, format);
	j = -1;
	while (format[++j])
	{
		 if (format[j] == '%' && format[j + 1] == 'd')
		 {
			i = va_arg(ap, int);
		 	ft_putnbr(i);
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
	ft_printf(argv[1], 42, 456);
	return 0;
}
