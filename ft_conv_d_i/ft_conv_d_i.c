/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:26:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 19:07:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_d_i(va_list pa, t_flags flags)
{
	int		local_pa;
	int		sign;
	int		space;
	int		len;

	local_pa = va_arg(pa, int);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen(local_pa) == 0) ? 1 : ft_nbrlen(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_l(va_list pa, t_flags flags)
{
	long	local_pa;
	int		sign;
	int		space;
	int		len;

	local_pa = va_arg(pa, long);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen_l(local_pa) == 0) ? 1 : ft_nbrlen_l(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_ll(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, long long);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	(local_pa < 0) ? ft_putchar('-') : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int_ll(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_h(va_list pa, t_flags flags)
{
	short		local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, int);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_hh(va_list pa, t_flags flags)
{
	char		local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, int);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_j(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, long long);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

int		ft_conv_d_i_z(va_list pa, t_flags flags)
{
	long long		local_pa;
	int				space;
	int				len;

	local_pa = va_arg(pa, long long);
	(flags.empty == 1) && (local_pa > 0) ? ft_putchar(' ') : 0;
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + space);
}
