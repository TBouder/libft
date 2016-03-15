/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:07 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 15:34:47 by tbouder          ###   ########.fr       */
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

int				ft_conv_x(va_list pa, t_flags flags, char *str)
{
	long	local_pa;
	long	value;
	int		space;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa == 4294967296) ? 0 : value;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	flags.diaiz == 1 ? ft_putstr("0x") : 0;
	flags.diaiz == 1 ? space += 2 : 0;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_precision(flags, value, 16, 0);
	ft_after(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count + space);
}

int				ft_conv_x_l(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	long long	value;
	int			space;

	local_pa = va_arg(pa, long long);
	// value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	value = (local_pa < 0) ? -local_pa : local_pa;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	flags.diaiz == 1 ? ft_putstr("0x") : 0;
	flags.diaiz == 1 ? space += 2 : 0;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_precision(flags, value, 16, 0);
	ft_after(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count + space);
}

int				ft_conv_x_ll(va_list pa, t_flags flags, char *str)
{
	long long	local_pa;
	long long	value;
	int			space;

	local_pa = va_arg(pa, long long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	str[-1] == ' ' ? ft_putchar(' ') : 0;
	space = str[-1] == ' ' ? 1 : 0;
	flags.diaiz == 1 ? ft_putstr("0x") : 0;
	flags.diaiz == 1 ? space += 2 : 0;
	ft_flag_r_justified(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	ft_put_precision(flags, value, 16, 0);
	ft_after(&flags, ft_strlen(ft_itoa_base(local_pa, 16)));
	return (ft_strlen(ft_itoa_base(value, 16)) + flags.spaces_count + space);
}

int		ft_launch_conv_x(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'x')
	{
		if (flags.length == 1)
			return (ft_conv_x_l(*pa, flags, str + index));
		else if (flags.length == 2)
			return (ft_conv_x_ll(*pa, flags, str + index));
		else
			return (ft_conv_x(*pa, flags, str + index));
	}
	return (0);
}
