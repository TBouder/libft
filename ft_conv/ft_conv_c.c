/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:28:47 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 13:14:00 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_c() add spaces before if needed //RISQUE DE CHANGER.
*/

void	ft_before_c(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces - v_len != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
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

/*
** The ft_after_c() function adds spaces after the output when the conditions
** are met.
*/

void	ft_after_c(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

int		ft_conv_c(va_list pa, t_flags flags)
{
	int		local_pa;

	local_pa = va_arg(pa, unsigned int);
	ft_before_c(&flags, 1);
	(!flags.display) ? ft_putchar(local_pa) : 0;
	ft_after_c(&flags, 1);
	return (1 + flags.spaces_count);
}
