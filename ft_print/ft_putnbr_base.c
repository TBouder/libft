/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:33:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/09 16:40:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_base() function prints the number nb according to the base
** to STDIN.
*/

#include "../libft.h"

void	ft_putnbr_base(int nb, int base)
{
	char	*str;

	str = "0123456789ABCDEF";
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
			ft_putnbr_base(nb / base, base);
			ft_putnbr_base(nb % base, base);
		}
	}
}
