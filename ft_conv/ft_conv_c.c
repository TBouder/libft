/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:28:47 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 11:06:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_c(va_list pa, t_flags flags, char *str)
{
	int		local_pa;
	int		space;

	space = 0;
	if (str[-1] == ' ')
	{
		ft_putchar(' ');
		space = 1;
	}
	local_pa = va_arg(pa, unsigned int);
	ft_flag_r_justified(&flags, 1);
	ft_putchar(local_pa);
	ft_flag_l_justified(&flags, 1);
	return (1 + flags.spaces_count + space);
}
