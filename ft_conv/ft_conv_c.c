/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:28:47 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 18:36:44 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_c(va_list pa, t_flags flags)
{
	int		local_pa;

	local_pa = va_arg(pa, unsigned int);
	ft_flag_r_justified(&flags, 1);
	ft_putchar(local_pa);
	ft_flag_l_justified(&flags, 1);
	return (1 + flags.spaces_count);
}
