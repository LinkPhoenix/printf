/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:54:22 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/14 11:54:22 by emlecerf         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("%%10d 	: |%10d|\n", 42);
	printf("%%d%%%% 	: |%d%%|\n", 42);
	printf("%%-d 	: |%-d|\n", 42);
	printf("%%010d 	: |%010d|\n", 42);
	printf("%%-3d 	: |%-3d|\n", 42);
	printf("%%10.5d 	: |%10.5d|\n", 42);
	printf("%%03d 	: |%03d|\n", 42);
	printf("%%-5d 	: |%-5d|\n", 42);
	printf("\033[0;31mflag '0' is ignored when flag '-' is present [-Wformat]\033[0m\n");
	printf("%%-0d 	: |%-0d| blablabla\n", 42);
	printf("%%5d 	: |%5d|\n", 42);
	printf("%%d 	: |%d|\n", 42);
	printf("%%-05d 	: |%-05d|\n", 42);
	printf("%%#o 	: |%#o |\n", "d");

	printf("%2$d\n", (double)43, (int)4);
printf("%2$d %1$lf\n", (double)43, (int)4);
}
