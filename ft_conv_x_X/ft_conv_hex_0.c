/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:24:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 13:47:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_before_x_spaces(t_flags *flags, int v_len, long long local_pa)
{
	(flags->diaiz == 1) ? flags->spaces -= 2 : 0;
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	while (flags->spaces-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar(' ');
	}
	(flags->preci == -1) && (local_pa == 0) ? ft_putchar(' ') : 0;
	(flags->preci == -1) && (local_pa == 0) ? flags->spaces_count++ : 0;
}

void	ft_before_x_zero(t_flags *flags, int v_len, long long value, int maj)
{
	(flags->diaiz == 1) ? flags->zero -= 2 : 0;
	(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
	(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar('0');
	}
}

void	ft_before_x(t_flags *flags, int v_len, long long value, int maj)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_x_spaces(flags, v_len, value);
	else if (flags->zero && flags->zero - v_len > 0)
	{
		ft_before_x_zero(flags, v_len, value, maj);
		maj = -1;
	}
	(maj == 1) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0X") : 0;
	(maj == 0) && (flags->diaiz == 1) && (value != 0) ? ft_putstr("0x") : 0;
	(flags->diaiz == 1) && (value != 0) ? flags->spaces_count += 2 : 0;
}

void	ft_after_hex(t_flags *flags, int v_len)
{
	(flags->preci == -1) ? flags->spaces-- : 0;
	(flags->diaiz) ? flags->spaces += 2 : 0;
	if (flags->spaces + v_len + flags->preci_diff < 0)
	{
		while (flags->spaces++ + v_len + flags->preci_diff < 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int		ft_launch_conv_x_X(va_list *pa, t_flags flags, char *str, int index)
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
