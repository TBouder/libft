/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/19 16:19:59 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main()
{
	// int		count = 42;
	// char	*i = "445452";
	// char	c = 'O';
	// int		d = 85;
	/*
		ft_nbrendl(ft_printf("HELLO YOU %10% !!\n"));				ft_nbrendl(printf("HELLO YOU %10% !!\n"));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10d !!\n", 42));			ft_nbrendl(printf("HELLO YOU %10d !!\n", 42));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10i !!\n", 42));			ft_nbrendl(printf("HELLO YOU %10i !!\n", 42));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("%20s", "HELLO YOU !!\n"));			ft_nbrendl(printf("%20s", "HELLO YOU !!\n"));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("%27p\n", &count));					ft_nbrendl(printf("%27p\n", &count));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELL%10c YO%10c !!\n", c, d));		ft_nbrendl(printf("HELL%10c YO%10c !!\n", c, d));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10o !!\n", count));		ft_nbrendl(printf("HELLO YOU %10o !!\n", count));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10x !!\n", count));		ft_nbrendl(printf("HELLO YOU %10x !!\n", count));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10X !!\n", count));		ft_nbrendl(printf("HELLO YOU %10X !!\n", count));
		printf("--------------------\n");
		ft_nbrendl(ft_printf("HELLO YOU %10u !!\n", count));		ft_nbrendl(printf("HELLO YOU %10u !!\n", count));
		printf("--------------------\n");
	    ft_nbrendl(ft_printf("%10p\n", &ft_printf));				ft_nbrendl(printf("%10p\n", &ft_printf));
		printf("--------------------\n");
	*/
    /*
		ft_printf("%s == ", NULL);							printf("%s\n", NULL);
	    ft_printf("%S == ", L"ݗݜशব");					    printf("%S\n", L"ݗݜशব");
	    ft_printf("%C == ", 15000);		 					printf("%C\n", 15000);
	*/
	// printf("%12x\n", 145);
	// printf("%12.1x\n", 145);
	// printf("%12.4x\n\n", 145);
	//
	// ft_printf("%12x\n", 145);
	// ft_printf("%12.1x\n", 145);
	// ft_printf("%12.4x\n", 145);
	// ft_printf("%-5.0x", 2500);
	// ft_printf("%-5.0o", 2500);
	int		l,k;
	int		i;
	l = ft_printf("{%015p}", &ft_putnbr);
	printf("\n");
	k = printf("{%015p}", &ft_putnbr);
	printf("\n");
	printf("%d vs %d\n", l, k);


	return 0;
}
