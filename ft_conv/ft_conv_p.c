/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/19 16:21:36 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_before(t_flags *flags, int v_len)
{
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

void	ft_middle(t_flags *flags, int v_len)
{
	if (flags->zero && flags->zero - v_len > 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
}

void	ft_after(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

void	ft_after_null(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
	else if (flags->zero && flags->zero - v_len > 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
}

int		ft_conv_p(va_list *pa, t_flags flags)
{
	int		*local_pa;

	local_pa = (va_arg(*pa, int*));
	if (local_pa == NULL)
	{
		ft_before(&flags, 3);
		(!flags.display) ? ft_putstr("0x0") : 0;
		ft_after_null(&flags, 3);
		return (3 + flags.spaces_count);
	}
	ft_before(&flags, ft_printf("%!x", local_pa) + 2);
	(!flags.display) ? ft_putstr("0x") : 0;
	ft_middle(&flags, ft_printf("%!x", local_pa) + 2);
	(!flags.display) ? ft_printf("%x", local_pa) : 0;
	ft_after(&flags, ft_printf("%!x", local_pa) + 2);
	return (ft_printf("%!x", local_pa) + flags.spaces_count + 2);
}
