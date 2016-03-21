/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 11:58:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_u() function launchs the conversion for u / U specifier.
*/

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

/*
** The ft_conv_u_l() function launchs the conversion for u / U specifier with l
** or ll.
*/

int		ft_conv_u_l(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = va_arg(pa, long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, local_pa);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_z() function launchs the conversion for u / U specifier with z.
*/

int		ft_conv_u_z(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = va_arg(pa, long long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, local_pa);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_j() function launchs the conversion for u / U specifier with j.
*/

int		ft_conv_u_j(va_list pa, t_flags flags)
{
	long long	local_pa;
	long long	value;
	int			len;

	local_pa = va_arg(pa, long long);
	value = (int)local_pa < 0 ? 0 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base_ull(value, 10));
	ft_before_u(&flags, len, local_pa);
	ft_put_preci_uni_ll(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}

/*
** The ft_conv_u_hh() function launchs the conversion for u / U specifier with
** hh.
*/

int		ft_conv_u_hh(va_list pa, t_flags flags)
{
	int			local_pa;
	int			len;
	int			value;

	local_pa = va_arg(pa, int);
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base(value, 10));
	ft_before_u(&flags, len, value);
	ft_put_precision_uni(&flags, value);
	ft_after_u(&flags, len);
	return (len + flags.spaces_count);
}
