/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:07 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 20:29:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_conv_x(va_list pa, t_flags flags, char *str)
{
	long	local_pa;
	long	value;
	int		space;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	ft_before_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), value, 0);
	ft_put_precision(flags, value, 16, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count + space);
}

int				ft_conv_x_l(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	int			space;

	local_pa = va_arg(pa, long long);
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	ft_before_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), local_pa, 0);
	ft_put_preci_hex_ll(flags, local_pa, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base_ull(local_pa, 16)) + flags.spaces_count
		+ space);
}
