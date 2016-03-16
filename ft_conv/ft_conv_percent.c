/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:23:27 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 15:01:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_after(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int				ft_conv_percent(t_flags flags)
{
	ft_flag_r_justified(&flags, ft_nbrlen(1));
	ft_putchar('%');
	ft_after(&flags, ft_nbrlen(1));
	return (1 + flags.spaces_count);
}
