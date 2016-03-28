/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 00:53:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	int	i;
	int	j;
	char str[32];

	i = ft_printf("Bonjour{b}, {0}%d\n", 2);
	// i = ft_printf("s", 17.0);
	// ft_putfloat(4683.3729376);
	// ft_putendl(str);
	ft_printf("\n\n");
	j = printf("Bonjour{4}, %d\n", 2);
	printf("\n%d vs %d\n", i, j);


	return (0);
}
