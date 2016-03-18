/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/19 00:23:12 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_p(va_list *pa, t_flags flags)
{
	int		*local_pa;

	local_pa = (va_arg(*pa, int*));
	if (local_pa == NULL)
	{
		(!flags.display) ? ft_putstr("0x0") : 0;
		return (3);
	}
	ft_printf("%#x", local_pa);
	return (ft_printf("%#!x", local_pa) + flags.spaces_count);
}
