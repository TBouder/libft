/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:07 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 16:08:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_x() function launchs the conversion for x specifier.
*/

int				ft_conv_x(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;
	// int		space;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	len = ft_strlen(ft_itoa_base(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), value, 0);
	ft_put_preci_hex(&flags, value, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_itoa_base(local_pa, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

/*
** The ft_conv_x_l() function launchs the conversion for x specifier with l,
** ll or j flag.
*/

int				ft_conv_x_l(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			len;

	local_pa = va_arg(pa, long long);
	len = ft_strlen(ft_itoa_base_ull(local_pa, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), local_pa, 0);
	ft_put_preci_hex_ll(&flags, local_pa, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_itoa_base(local_pa, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

/*
** The ft_conv_x_hh() function launchs the conversion for X specifier with hh.
*/

int		ft_conv_x_hh(va_list pa, t_flags flags)
{
	int			local_pa;
	int			value;
	int			len;

	local_pa = va_arg(pa, int);
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base_ull(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(value, 16)), value, 0);
	ft_put_preci_hex_ll(&flags, value, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(value, 16)));
	ft_itoa_base(value, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

/*
** The ft_conv_x_z() function launchs the conversion for x specifier with z.
*/

int		ft_conv_x_z(va_list pa, t_flags flags)
{
	int			local_pa;
	int			value;
	int			len;

	local_pa = va_arg(pa, int);
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base_ull(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(value, 16)), value, 0);
	ft_put_preci_hex_ll(&flags, value, 0);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(value, 16)));
	ft_itoa_base(value, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}
