/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:32:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/23 14:09:21 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrlen_l() function count the number of digit in n (long).
*/

#include "../ft_printf.h"

int		ft_nbrlen_l(long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_nbrlen_ll(long long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_nbrlen_ull(unsigned long long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_nbrlen_base_oll(unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
