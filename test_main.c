/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/13 13:22:36 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	int	i;
	int	j;

	i = ft_printf("Bonjour, %.5s, %d, %lh020d \n",  "SAlut les coupaings", 42, 42000000000000);
	ft_printf("\n\n\n");
	j = printf("Bonjour, %.5s, %d, %lh020d \n",  "SAlut les coupaings", 42, 42000000000000);
	printf("\n%d vs %d\n", i, j);


	return (0);
}
