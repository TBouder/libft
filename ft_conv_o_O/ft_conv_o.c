/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 12:21:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_o() function launchs the conversion for o / O specifier.
*/

int		ft_conv_o(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	ft_before_o(&flags, len, 0, local_pa);
	ft_put_precision_oct(&flags, value);
	ft_after_o(&flags, len);
	local_pa == 0 && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

/*
** The ft_conv_o_ll() function launchs the conversion for o / O specifier with
** ll flag.
*/

int		ft_conv_o_ll(va_list pa, t_flags flags)
{
	unsigned long long	local_pa;
	int					len;

	local_pa = va_arg(pa, unsigned long long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 8));
	ft_before_o(&flags, len, 0, local_pa);
	ft_put_precision_oct_ll(&flags, local_pa);
	ft_after_o(&flags, len);
	local_pa == 0 && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_hh() function launchs the conversion for u / U specifier with
** hh.
*/

int		ft_conv_o_hh(va_list pa, t_flags flags)
{
	int			local_pa;
	int			len;
	short		value;

	local_pa = va_arg(pa, int);
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base(value, 10));
	ft_before_o(&flags, len, 0, value);
	ft_put_precision_oct(&flags, value);
	ft_after_o(&flags, len);
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_j() function launchs the conversion for u / U specifier with j.
*/

int		ft_conv_o_j(va_list pa, t_flags flags)
{
	long		local_pa;
	int			len;

	local_pa = va_arg(pa, long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 8));
	ft_before_o(&flags, len, 0, local_pa);
	ft_put_precision_oct_ll(&flags, local_pa);
	ft_after_o(&flags, len);
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_z() function launchs the conversion for u / U specifier with j.
*/

int		ft_conv_o_z(va_list pa, t_flags flags)
{
	long		local_pa;
	int			len;

	local_pa = va_arg(pa, long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 8));
	ft_before_o(&flags, len, 0, local_pa);
	ft_put_precision_oct_ll(&flags, local_pa);
	ft_after_o(&flags, len);
	return (len + flags.spaces_count);
}
