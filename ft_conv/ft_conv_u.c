/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 23:52:04 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_u(va_list pa, t_flags flags)
{
	int		local_pa;
	long	value;

	local_pa = va_arg(pa, unsigned int);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	ft_flag_r_justified(&flags, ft_nbrlen(value));
	ft_put_precision_base(flags, value, 10, 0);
	ft_flag_l_justified(&flags, ft_nbrlen(value));
	return (ft_nbrlen(value) + flags.spaces_count);
}
