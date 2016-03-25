/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 15:49:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
/*
	int		i, j;

	i = ft_printf("%D\n%d\n%o\n%O\n%u\n%U\n%zx\n%zX\n", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42);
	printf("\n\n");
	j = printf("%D\n%d\n%o\n%O\n%u\n%U\n%zx\n%zX\n", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42);

	printf("\n%d vs %d\n", i, j);
	ft_printf("\n");
    ft_printf("%%\n");
    ft_printf("%d\n", 42);
    ft_printf("%d%d\n", 42, 41);
    ft_printf("%d%d%d\n", 42, 43, 44);
    ft_printf("%ld\n", 2147483647);
    ft_printf("%lld\n", 9223372036854775807);
    ft_printf("%x\n", 505);
    ft_printf("%X\n", 505);
    ft_printf("%p\n", &ft_printf);
    ft_printf("%20.15d\n", 54321);
    ft_printf("%-10d\n", 3);
    ft_printf("% d\n", 3);
    ft_printf("%+d\n", 3);
    ft_printf("%010d\n", 1);
    ft_printf("%hhd\n", 0);
    ft_printf("%jd\n", 9223372036854775807);
    ft_printf("%zd\n", 4294967295);
    ft_printf("%\n");
    ft_printf("%U\n", 4294967295);
    ft_printf("%u\n", 4294967295);
    ft_printf("%o\n", 40);
    ft_printf("%%#08x\n", 42);
    ft_printf("%x\n", 1000);
    ft_printf("%#X\n", 1000);
    ft_printf("%s\n", NULL);
    ft_printf("%S\n", L"ݗݜशব");
    ft_printf("%s%s\n", "test", "test");
    ft_printf("%s%s%s\n", "test", "test", "test");
    ft_printf("%C\n", 15000);
*/
	int	i;
	int	j;

	i = ft_printf("% 10.d", 256);
	ft_printf("\n\n");
	j = printf("% 10.d", 256);
	printf("\n%d vs %d", i, j);

	return (0);
}
