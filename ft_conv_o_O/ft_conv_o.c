/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 12:23:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_precision_oct(t_flags flags, long long local_pa)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	while (flags.precision - len > 0)
	{
		ft_putchar('0');
		flags.precision -= 1;
	}
	if (local_pa == 0 && flags.precision != -1)
		ft_putnbr_base(local_pa, 8, 0);
	else if (local_pa != 0)
		ft_putnbr_base(local_pa, 8, 0);
}

void	ft_before_o_O(t_flags *flags, int s_local_pa, int index)
{
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - s_local_pa + flags->diaiz > 0)
	{
		while (flags->spaces - s_local_pa + flags->diaiz != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			ft_putchar(' ');
		}
		(flags->precision == -1) ? ft_putchar(' ') : 0;
		(flags->precision == -1) ? flags->spaces_count++ : 0;
	}
	else if (flags->spaces == 0 && flags->zero != 0)
	{
		(flags->diaiz == 1) ? ft_putstr("0") : 0;
		index = 1;
		while (flags->zero-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
	(index == 0) && (flags->diaiz == 1) ? ft_putstr("0") : 0;
	(flags->diaiz == 1) ? flags->spaces_count += 1 : 0;
}

void	ft_after_o_O(t_flags *flags, int s_local_pa)
{
	if (flags->spaces + s_local_pa < 0)
	{
		while (flags->spaces++ + s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int		ft_conv_o(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	ft_before_o_O(&flags, len, 0);
	ft_put_precision_oct(flags, value);
	ft_after_o_O(&flags, len);
	local_pa == 0 && flags.precision == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

int			ft_launch_conv_o_O(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'o')
	{
		// if (flags.length == 1 || flags.length == 2 || flags.length == 5)
		// 	return (ft_conv_o_l(*pa, flags, str + index));
		// else
			return (ft_conv_o(*pa, flags));
	}
	return (0);
}
