/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uni_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:44:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 13:53:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_before_u_spaces(t_flags *flags, int v_len, long long local_pa)
{
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	while (flags->spaces-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar(' ');
	}
	(flags->preci == -1) && (local_pa == 0) ? ft_putchar(' ') : 0;
	(flags->preci == -1) && (local_pa == 0) ? flags->spaces_count++ : 0;
}

void	ft_before_u_zero(t_flags *flags, int v_len)
{
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		ft_putchar('0');
	}
}

void	ft_before_u(t_flags *flags, int v_len, long long local_pa)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_u_spaces(flags, v_len, local_pa);
	else if (flags->zero && flags->zero - v_len > 0)
		ft_before_u_zero(flags, v_len);
}

void	ft_after_u(t_flags *flags, int v_len)
{
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

int		ft_launch_conv_u_U(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'u')
	{
		if (flags.length == 1 || flags.length == 2)
			return (ft_conv_u_l(*pa, flags));
		else
			return (ft_conv_u(*pa, flags));
	}
	return (0);
}
