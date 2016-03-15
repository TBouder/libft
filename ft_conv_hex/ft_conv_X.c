/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 17:35:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_conv_X(va_list pa, t_flags flags, char *str)
{
	long	local_pa;
	long	value;
	int		space;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_precision(flags, value, 16, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count + space);
}

int				ft_conv_X_l(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	int			space;

	local_pa = va_arg(pa, long long);
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	flags.diaiz == 1 ? ft_putstr("0x") : 0;
	flags.diaiz == 1 ? space += 2 : 0;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_preci_hex_ll(flags, local_pa, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base_ull(local_pa, 16)) + flags.spaces_count + space);
}
