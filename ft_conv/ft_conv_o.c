/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 23:52:06 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_o(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 8)));
	ft_put_precision_base(flags, value, 8, 0);
	ft_flag_l_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 8)));
	return (ft_strlen(ft_itoa_base(value, 8)) + flags.spaces_count);
}
