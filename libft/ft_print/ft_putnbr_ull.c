/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 12:48:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_ll() function prints the number nb (unsigned ll) to STDIN.
*/

#include "../libft.h"

void	ft_putnbr_ll(unsigned long long nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_ll(nb / 10);
		ft_putnbr_ll(nb % 10);
	}
}
