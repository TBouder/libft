/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 19:35:21 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 13:47:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_precision_oct(t_flags *flags, long long local_pa)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	while (flags->preci - len - flags->diaiz > 0)
	{
		ft_putchar('0');
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff += 1;
	}
	if (local_pa == 0 && flags->preci != -1)
		ft_putnbr_base(local_pa, 8, 0);
	else if (local_pa != 0)
		ft_putnbr_base(local_pa, 8, 0);
}

void	ft_before_o_spaces(t_flags *flags, int v_len, long long local_pa)
{
	(flags->diaiz == 1) ? flags->spaces-- : 0;
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	while (flags->spaces-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar(' ');
	}
	(flags->preci == -1) && (local_pa == 0) ? ft_putchar(' ') : 0;
	(flags->preci == -1) && (local_pa == 0) ? flags->spaces_count++ : 0;
}

void	ft_before_o_zero(t_flags *flags, int v_len)
{
	(flags->diaiz == 1) ? flags->zero-- : 0;
	(flags->diaiz == 1) ? ft_putstr("0") : 0;
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar('0');
	}
}

void	ft_before_o(t_flags *flags, int v_len, int index, long long local_pa)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_o_spaces(flags, v_len, local_pa);
	else if (flags->zero && flags->zero - v_len > 0)
	{
		ft_before_o_zero(flags, v_len);
		index = 1;
	}
	(index == 0) && (flags->diaiz == 1) ? ft_putstr("0") : 0;
	(flags->diaiz == 1) ? flags->spaces_count++ : 0;
}

void	ft_after_o(t_flags *flags, int v_len)
{
	(flags->preci == -1) ? flags->spaces-- : 0;
	(flags->diaiz) ? flags->spaces++ : 0;
	if (flags->spaces + v_len + flags->preci_diff < 0)
	{
		while (flags->spaces + v_len + flags->preci_diff < 0)
		{
			flags->spaces++;
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}
