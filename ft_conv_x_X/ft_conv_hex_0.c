/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:24:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 16:21:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_before_hex_spaces(t_flags *flags, int s_local_pa)
{
	(flags->diaiz == 1) ? flags->spaces -= 2 : 0;
	while (flags->spaces-- - s_local_pa != 0)
	{
		flags->spaces_count++;
		ft_putchar(' ');
	}
	(flags->preci == -1) ? ft_putchar(' ') : 0;
	(flags->preci == -1) ? flags->spaces_count++ : 0;
}

void		ft_before_hex_zero(t_flags *flags, int s_local_pa, long long value, int maj)
{
	(flags->diaiz == 1) ? flags->zero -= 2 : 0;
	(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
	(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
	while (flags->zero-- - s_local_pa != 0)
	{
		flags->spaces_count++;
		ft_putchar('0');
	}
}

void		ft_before_hex(t_flags *flags, int s_local_pa, long long value, int maj)
{
	if (flags->spaces && flags->spaces - s_local_pa > 0)
		ft_before_hex_spaces(flags, s_local_pa);
	else if (flags->zero && flags->zero - s_local_pa > 0)
	{
		ft_before_hex_zero(flags, s_local_pa, value, maj);
		maj = -1;
	}
	(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
	(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
	(flags->diaiz == 1) && (value != 0) ? flags->spaces_count += 2 : 0;
}


void		ft_after_hex(t_flags *flags, int s_local_pa)
{
	(flags->diaiz) ? flags->spaces += 2 : 0;
	if (flags->spaces + s_local_pa < 0)
	{
		while (flags->spaces++ + s_local_pa < 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int			ft_launch_conv_x_X(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'X')
	{
		if (flags.length == 1 || flags.length == 2 || flags.length == 5)
			return (ft_conv_X_l(*pa, flags, str + index));
		else
			return (ft_conv_X(*pa, flags, str + index));
	}
	else if (str[index] == 'x')
	{
		if (flags.length == 1 || flags.length == 2 || flags.length == 5)
			return (ft_conv_x_l(*pa, flags, str + index));
		else
			return (ft_conv_x(*pa, flags, str + index));
	}
	return (0);
}
