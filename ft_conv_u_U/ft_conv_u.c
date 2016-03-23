/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/23 16:37:29 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_u(va_list pa, t_flags flag)
{
	long long	lpa;
	long long	value;
	int			len;

	flag.l == 0 || flag.l == 4 ? lpa = va_arg(pa, unsigned int) : 0;
	flag.l == 1  || flag.l == 2 || flag.l == 3 || flag.l == 5 || flag.l == 6
		? lpa = va_arg(pa, long) : 0;
	value = (flag.l == 0 && lpa < 0) ? 4294967296 + lpa : lpa;
	value = (flag.l == 4) ? lpa % 256 : lpa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flag, len, value);
	ft_put_preci_uni_ll(&flag, value);
	ft_after_u(&flag, len);
	(flag.l == 0 && value == 0 && flag.preci == -1) ? len-- : 0;
	return (len + flag.spaces_count);
}

int		ft_U(va_list pa, t_flags flag)
{
	long long	local_pa;
	int			len;

	local_pa = va_arg(pa, long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 10));
	ft_before_u(&flag, len, local_pa);
	ft_put_preci_uni_ll(&flag, local_pa);
	ft_after_u(&flag, len);
	return (len + flag.spaces_count);
}

int		ft_conv_u(va_list pa, t_flags flags)
{
	long long	local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, unsigned int);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(local_pa, 10));

	ft_before_u(&flags, len, value);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	value == 0 && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

int		ft_conv_u_l(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			len;

	local_pa = va_arg(pa, long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 10));
	ft_before_u(&flags, len, local_pa);
	ft_put_preci_uni_ll(&flags, local_pa);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

int		ft_conv_u_z(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = va_arg(pa, long long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, value);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

int		ft_conv_u_j(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = va_arg(pa, long long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, value);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

int		ft_conv_u_hh(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = (short)va_arg(pa, int);
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, value);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}
