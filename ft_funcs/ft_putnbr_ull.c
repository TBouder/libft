/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 19:20:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_ull() function prints the number nb (unsigned ull) to STDIN.
*/

#include "../ft_printf.h"

void	ft_putnbr_ull(unsigned long long nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_ull(nb / 10);
		ft_putnbr_ull(nb % 10);
	}
}
