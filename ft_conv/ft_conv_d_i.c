/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:26:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 23:52:04 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_d_i(va_list pa, t_flags flags)
{
	int		local_pa;
	int		sign;

	local_pa = va_arg(pa, int);
	sign = local_pa < 0 ? 1 : 0;
	ft_flag_r_justified(&flags, ft_nbrlen(local_pa));
	ft_put_precision_base(flags, local_pa, 10, 0);
	ft_flag_l_justified(&flags, ft_nbrlen(local_pa) + sign);
	return (ft_nbrlen(local_pa) + flags.spaces_count + sign);
}
