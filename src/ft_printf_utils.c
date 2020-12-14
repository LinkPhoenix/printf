/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:54:22 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/14 12:02:10 by emlecerf         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
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

void		print_base(unsigned long nbr, char *base, int len_base)
{
	if (nbr / len_base)
		print_base((nbr / len_base), base, len_base);
	write(1, &base[nbr % len_base], 1);
}