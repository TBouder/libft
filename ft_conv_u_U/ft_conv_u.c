/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 18:14:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_put_preci_ll(t_flags flags, long long local_pa)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen_ll(local_pa);
	while (flags.preci - len > 0)
	{
		ft_putchar('0');
		flags.preci -= 1;
	}
	ft_putnbr_base_ull(local_pa, 10, 0);
}

int		ft_conv_u(va_list pa, t_flags flags)
{
	int		local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, unsigned int);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_nbrlen_ll(value) == 0 ? 1 : ft_nbrlen_ll(value);
	ft_flag_r_justified(&flags, len);
	ft_put_precision(flags, value, 10, 0);
	ft_flag_l_justified(&flags, len);
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
	ft_flag_r_justified(&flags, len);
	ft_put_preci_ll(flags, value);
	ft_flag_l_justified(&flags, len);
	return (len + flags.spaces_count);
}

int		ft_launch_conv_u_U(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'u')
	{
		if (flags.length == 1 || flags.length == 2)
			return (ft_conv_u_l(*pa, flags));
		else
			return (ft_conv_u(*pa, flags));
	}
	return (0);
}
