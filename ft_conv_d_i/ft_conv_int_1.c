/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:23:55 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 23:29:08 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_preci_int_ll() function adjusts the precision before displaying
** the output (for long long).
*/

void	ft_put_preci_int_ll(t_flags *flags, long long local_pa)
{
	int		len;

	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	if (local_pa < 0 && flags->preci > 0 && (!flags->display))
		ft_putchar('-');
	while (flags->preci - len > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	if (local_pa < 0)
	{
		if (flags->zero > 0)
			local_pa = -local_pa;
		else if (flags->preci_diff != 0)
			local_pa = -local_pa;
	}
	if (local_pa == -1)
		(!flags->display) ? ft_putnbr_ull(-local_pa) : 0;
	else
		(!flags->display) ? ft_putnbr_ull(local_pa) : 0;
}

/*
** The ft_put_preci_int() function adjusts the precision before displaying
** the output.
*/

void	ft_put_preci_int(t_flags *flags, long long local_pa)
{
	int		len;

	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	if (local_pa < 0 && flags->preci > 0 && (!flags->display))
		ft_putchar('-');
	while (flags->preci - len > 0)
	{
		(!flags->display) ? ft_putchar('0'): 0;
		flags->preci_diff += 1;
		flags->spaces_count += 1;
		flags->preci -= 1;
	}
	if (local_pa < 0)
	{
		if (flags->zero_base > 0)
			local_pa = -local_pa;
		else if (flags->preci_diff != 0)
			local_pa = -local_pa;
		else if (flags->preci > 0)
			local_pa = -local_pa;
	}
	if (!(flags->preci == -1 && local_pa == 0))
		(!flags->display) ? ft_putnbr_base(local_pa, 10, 0) : 0;
	else
		flags->spaces_count--;
}
