/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:28:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	int	i;
	int	j;

	i = ft_printf("Bonjour, %b\n", 420);
	ft_printf("\n\n");
	j = printf("Bonjour, 110100100\n");
	printf("\n%d vs %d\n", i, j);


	return (0);
}
