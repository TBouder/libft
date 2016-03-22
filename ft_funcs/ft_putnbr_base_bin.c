/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:36:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 22:03:40 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_base_bin(unsigned long long nb, int base)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb < (unsigned long long) base)
		ft_putchar(str[nb]);
	else
	{
		ft_putnbr_base_bin(nb / 10, 10);
		ft_putnbr_base_bin(nb % base, base);
	}
}
