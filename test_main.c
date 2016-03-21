/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 16:19:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
# include <wchar.h>

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

	int		l,k;
	l = ft_printf("%S", L"ݗݜशব");
	printf("\n");
	k = printf("%S", L"ݗݜशব");
	printf("\n");
	printf("%d vs %d\n", l, k);


	return 0;
}
