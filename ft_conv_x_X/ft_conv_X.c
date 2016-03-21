/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 12:24:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_X() function launchs the conversion for X specifier.
*/

int		ft_conv_X(va_list pa, t_flags flags, char *str)
{
	long	local_pa;
	long	value;
	int		space;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	(str[-1] == ' ') && (!flags.display) ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	len = ft_strlen(ft_itoa_base(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), value, 1);
	ft_put_preci_hex(&flags, value, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_itoa_base(local_pa, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count + space);
}

/*
** The ft_conv_X_l() function launchs the conversion for X specifier with l,
** ll or j flag.
*/

int		ft_conv_X_l(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	int			space;
	int			len;

	local_pa = va_arg(pa, long long);
	(str[-1] == ' ') && (!flags.display) ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	len = ft_strlen(ft_itoa_base_ull(local_pa, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(local_pa, 16)), local_pa, 1);
	ft_put_preci_hex_ll(&flags, local_pa, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_itoa_base(local_pa, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count + space);
}

/*
** The ft_conv_X_hh() function launchs the conversion for X specifier with hh.
*/

int		ft_conv_X_hh(va_list pa, t_flags flags, char *str)
{
	int			local_pa;
	int			value;
	int			space;
	int			len;

	local_pa = va_arg(pa, int);
	(str[-1] == ' ') && (!flags.display) ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base_ull(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(value, 16)), value, 1);
	ft_put_preci_hex_ll(&flags, value, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(value, 16)));
	ft_itoa_base(value, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count + space);
}

/*
** The ft_conv_X_z() function launchs the conversion for X specifier with z.
*/

int		ft_conv_X_z(va_list pa, t_flags flags, char *str)
{
	int			local_pa;
	int			value;
	int			space;
	int			len;

	local_pa = va_arg(pa, int);
	(str[-1] == ' ') && (!flags.display) ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	value = local_pa % 256;
	len = ft_strlen(ft_itoa_base_ull(value, 16));
	ft_before_x(&flags, ft_strlen(ft_itoa_base(value, 16)), value, 1);
	ft_put_preci_hex_ll(&flags, value, 1);
	ft_after_hex(&flags, ft_strlen(ft_itoa_base(value, 16)));
	ft_itoa_base(value, 16)[0] == '0' && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count + space);
}
