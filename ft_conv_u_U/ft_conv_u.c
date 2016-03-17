/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 13:56:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_put_preci_ll(t_flags *flags, long long local_pa)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen_ll(local_pa);
	while (flags->preci - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff++;
	}
	if (local_pa == 0 && flags->preci != -1)
		ft_putnbr_base_ull(local_pa, 10, 0);
	else if (local_pa != 0)
		ft_putnbr_base_ull(local_pa, 10, 0);
}

void	ft_put_precision_uni(t_flags *flags, long long local_pa)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(ft_itoa_base(local_pa, 10));
	while (flags->preci - len - flags->diaiz > 0)
	{
		ft_putchar('0');
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff++;
	}
	if (local_pa == 0 && flags->preci != -1)
		ft_putnbr_base(local_pa, 10, 0);
	else if (local_pa != 0)
		ft_putnbr_base(local_pa, 10, 0);
}

int		ft_conv_u(va_list pa, t_flags flags)
{
	int		local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, unsigned int);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = (ft_nbrlen_ll(value) == 0) ? 1 : ft_nbrlen_ll(value);
	ft_before_u(&flags, len, local_pa);
	ft_put_precision_uni(&flags, value);
	ft_after_u(&flags, len);
	value == 0 && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

int		ft_conv_u_l(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			len;
	long long	value;

	local_pa = va_arg(pa, long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, local_pa);
	ft_put_preci_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}
