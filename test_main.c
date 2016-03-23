/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/23 13:59:59 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main()
{
	// setlocale(LC_ALL, "en_US.UTF-8");
	// char		*bin;
	// int			*nbr;
	// int			i;
	//
	// i = 0;
	// bin = ft_itoa_base(L'米', 2);
	// nbr = ft_parse_binary(ft_atoi_ll(bin));
	// while (nbr[i])
	// {
	// 	nbr[i] = ft_binary_to_decimal(nbr[i]);
	// 	ft_putchar(nbr[i]);
	// 	i++;
	// }
	// ft_putchar('\n');
	setlocale(LC_ALL, "en_US.UTF-8");

	int		i, j;

	i = ft_printf("%lo", ULONG_MAX);
	printf("\n\n");
	j = printf("%lo", ULONG_MAX);

	printf("\n%d vs %d\n", i, j);
	return 0;
}
