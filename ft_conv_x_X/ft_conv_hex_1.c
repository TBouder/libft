/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:20:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 09:22:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_put_preci_hex_ll(t_flags *flags, long long local_pa, int maj)
{
	int		len;

	len = ft_strlen(ft_itoa_base(local_pa, 16));
	while (flags->preci - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	ft_putnbr_base_ull(local_pa, 16, maj);
}

void		ft_put_preci_hex(t_flags *flags, long long local_pa, int maj)
{
	int		len;

	len = ft_strlen(ft_itoa_base(local_pa, 16));
	while (flags->preci - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	if (ft_itoa_base(local_pa, 16)[0] == '0' && flags->preci != -1)
		ft_putnbr_base(local_pa, 16, maj);
	else if (ft_itoa_base(local_pa, 16)[0] != '0')
		ft_putnbr_base(local_pa, 16, maj);
}
