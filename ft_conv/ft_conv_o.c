/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 01:29:07 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_before(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - s_local_pa > 0)
	{
		while (flags->spaces-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
	else if (flags->spaces == 0 && flags->zero != 0)
	{
		while (flags->zero-- - s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar('0');
		}
	}
}

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

int				ft_conv_o(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	ft_before(&flags, len);
	ft_put_precision_base(flags, value, 8, 0);
	ft_after(&flags, len);
	return (len + flags.spaces_count );
}
