/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/22 16:05:39 by tbouder          ###   ########.fr       */
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

	i = ft_printf("%C", 0);
	printf("\n\n");
	j = printf("%C", 0);

	printf("\n%d vs %d\n", i, j);
	return 0;
}

// 1110110001
// 110xxxxx 10xxxxxx
// 11001110 10110001

// 111110001110011
// 1110xxxx 10xxxxxx 10xxxxxx
// 1110.0111 10.110001 10.110011
