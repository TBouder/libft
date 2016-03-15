/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:23:27 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 00:48:07 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int				ft_conv_percent(t_flags flags)
{
	ft_flag_r_justified(&flags, ft_nbrlen(1));
	ft_putchar('%');
	ft_after(&flags, ft_nbrlen(1));
	return (1 + flags.spaces_count);
}
