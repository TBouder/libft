/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 00:49:10 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_after(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	if (flags->spaces + s_local_pa < 0)
	{
		while (flags->spaces++ + s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int				ft_conv_X(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_precision_base(flags, value, 16, 1);
	ft_after(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count);
}
