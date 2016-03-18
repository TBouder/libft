/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 15:44:32 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_before(t_flags *flags, int v_len)
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
	else if (flags->spaces == 0 && flags->zero != 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
}

static void		ft_after(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
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

int		ft_conv_p(va_list *pa, t_flags flags, char *str)
{
	int		*local_pa;
	long	len;
	str = 0;

	local_pa = (va_arg(*pa, int*));
	len = ft_strlen(ft_itoa_base(local_pa[-1], 16));
	ft_before(&flags, ft_nbrlen(*local_pa) + len);
	ft_printf("%#x", local_pa);
	ft_after(&flags, ft_nbrlen(*local_pa) + len);
	return (ft_printf("%#!x", local_pa) + flags.spaces_count);
}
