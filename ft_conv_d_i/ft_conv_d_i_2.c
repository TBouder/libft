/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:21:50 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 19:47:27 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_d_i_l() function launchs the conversion for d / i specifier
** with j flag.
*/

int		ft_conv_d_i_j(va_list pa, t_flags flags)
{
	long long	local_pa;
	int			sign;
	int			space;
	int			len;

	local_pa = va_arg(pa, long long);
	if (flags.empty == 1 && local_pa > 0 && (!flags.display))
		ft_putchar(' ');
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	sign = (local_pa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + sign + space);
}

/*
** The ft_conv_d_i_l() function launchs the conversion for d / i specifier
** with z flag.
*/

int		ft_conv_d_i_z(va_list pa, t_flags flags)
{
	long long		local_pa;
	int				space;
	int				len;

	local_pa = va_arg(pa, long long);
	if (flags.empty == 1 && local_pa > 0 && (!flags.display))
		ft_putchar(' ');
	space = (flags.empty == 1) && (local_pa > 0) ? 1 : 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	ft_before_d_i(&flags, len, local_pa);
	ft_put_preci_int(&flags, local_pa);
	ft_after_d_i(&flags, len, local_pa);
	return (len + flags.spaces_count + space);
}
