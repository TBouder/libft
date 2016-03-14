/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 18:36:54 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_p(va_list *pa, t_flags flags)
{
	int		local_pa;

	local_pa = (va_arg(*pa, int));
	ft_flag_r_justified(&flags, ft_nbrlen(local_pa) + 4);
	ft_putstr("0x7fff");
	ft_putnbr_base(local_pa, 16, 0);
	ft_flag_l_justified(&flags, ft_nbrlen(local_pa) + 4);
	return (6 + ft_strlen(ft_itoa_base(local_pa, 16)) + flags.spaces_count);
}
