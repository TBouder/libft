/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:07:04 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 01:32:42 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_preci_int_ll(t_flags *flags, long long local_pa)
{
	int		len;

	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	(local_pa < 0) && (flags->preci > 0) ? ft_putchar('-') : 0;
	while (flags->preci - len > 0)
	{
		ft_putchar('0');
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	if (local_pa < 0)
	{
		if (flags->zero > 0)
			local_pa = -local_pa;
		else if (flags->preci_diff != 0)
			local_pa = -local_pa;
	}
	ft_putnbr_ull(local_pa);
}

void	ft_put_preci_int(t_flags *flags, long long local_pa)
{
	int		len;

	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	(local_pa < 0) && (flags->preci > 0) ? ft_putchar('-') : 0;
	while (flags->preci - len > 0)
	{
		ft_putchar('0');
		flags->preci_diff += 1;
		flags->spaces_count += 1;
		flags->preci -= 1;
	}
	if (local_pa < 0)
	{
		if (flags->zero > 0)
			local_pa = -local_pa;
		else if (flags->preci_diff != 0)
			local_pa = -local_pa;
		else if (flags->preci > 0)
			local_pa = -local_pa;
	}
	if (!(flags->preci == -1 && local_pa == 0))
		ft_putnbr_base(local_pa, 10, 0);
	else
		flags->spaces_count--;
}

void	ft_before_d_i(t_flags *flags, int v_len, long long local_pa)
{
	int		i;

	i = 0;
	if (flags->plus == 1 && flags->spaces > flags->preci + v_len)
		i = 1;
	else
	{
		(flags->plus == 1) && (local_pa >= 0) ? ft_putchar('+') : 0;
		(flags->plus == 1) && (local_pa >= 0) ? flags->spaces_count++ : 0;
	}
	(flags->preci > 0) && (flags->preci > v_len) ? v_len = flags->preci : 0;
	(flags->preci > 0) && (flags->spaces > flags->preci) && (flags->empty == 1) ? v_len++ : 0;
	(flags->preci > 0) && (flags->spaces > flags->preci) && (flags->plus == 1) ? v_len++ : 0;
	(flags->preci == -1) && (local_pa == 0) ? v_len-- : 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		(local_pa < 0) ? flags->spaces-- : 0;
		while (flags->spaces-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
		if (i == 1)
		{
			(flags->plus == 1) && (local_pa >= 0) ? ft_putchar('+') : 0;
			(flags->plus == 1) && (local_pa >= 0) ? flags->spaces_count++ : 0;
		}

	}
	else if (flags->zero && flags->zero - v_len > 0)
	{
		(local_pa < 0) ? ft_putchar('-') : 0;
		(local_pa < 0) ? flags->zero-- : 0;
		(flags->plus == 1) && (local_pa < 0) ? flags->zero++ : 0;
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
		if (i == 1)
		{
			(flags->plus == 1) && (local_pa >= 0) ? ft_putchar('+') : 0;
			(flags->plus == 1) && (local_pa >= 0) ? flags->spaces_count++ : 0;
		}
	}
}

void	ft_after_d_i(t_flags *flags, int v_len, long long local_pa)
{
	(local_pa < 0) ? v_len++ : 0;
	(flags->plus == 1 && flags->minus == 1) ? v_len++ : 0;

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

int		ft_launch_conv_d_i(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'd' || str[index] == 'i')
	{
		if (flags.length == 1)
			return (ft_conv_d_i_l(*pa, flags));
		else if (flags.length == 2)
			return (ft_conv_d_i_ll(*pa, flags));
		else if (flags.length == 3)
			return (ft_conv_d_i_h(*pa, flags));
		else if (flags.length == 4)
			return (ft_conv_d_i_hh(*pa, flags));
		else if (flags.length == 5)
			return (ft_conv_d_i_j(*pa, flags));
		else if (flags.length == 6)
			return (ft_conv_d_i_z(*pa, flags));
		else
			return (ft_conv_d_i(*pa, flags));
	}
	return (0);
}
