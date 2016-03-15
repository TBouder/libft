/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 11:07:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_u(va_list pa, t_flags flags, char *str)
{
	int		local_pa;
	long	value;
	int		space;

	space = 0;
	if (str[-1] == ' ')
	{
		ft_putchar(' ');
		space = 1;
	}
	local_pa = va_arg(pa, unsigned int);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	ft_flag_r_justified(&flags, ft_nbrlen(value));
	ft_put_precision(flags, value, 10, 0);
	ft_flag_l_justified(&flags, ft_nbrlen(value));
	return (ft_nbrlen(value) + flags.spaces_count + space);
}
