/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:33:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 14:34:58 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_base() function prints the number nb according to the base
** to STDIN.
*/

#include "../libft.h"

void	ft_putnbr_base(long nb, int base, int maj)
{
	char	*str;

	str = maj ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nb < -2147483647)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb < base)
			ft_putchar(str[nb]);
		else
		{
			ft_putnbr_base(nb / base, base, maj);
			ft_putnbr_base(nb % base, base, maj);
		}
	}
}
