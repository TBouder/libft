/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ull.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:33:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 15:56:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_base_ull() function prints the number nb according to the base
** to STDIN.
*/

#include "../libft.h"

void	ft_putnbr_base_ull(unsigned long long nb, int base, int maj)
{
	char	*str;

	str = maj ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nb < (unsigned long long)base)
		ft_putchar(str[nb]);
	else
	{
		ft_putnbr_base_ull(nb / base, base, maj);
		ft_putnbr_base_ull(nb % base, base, maj);
	}
}
