/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 13:46:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_o(va_list pa, t_flags flags)
{
	long	local_pa;
	long	value;
	int		len;

	local_pa = va_arg(pa, long);
	value = (local_pa < 0) ? 4294967296 + local_pa : local_pa;
	len = ft_strlen(ft_itoa_base(local_pa, 8));
	ft_before_o(&flags, len, 0, local_pa);
	ft_put_precision_oct(&flags, value);
	ft_after_o(&flags, len);
	local_pa == 0 && flags.preci == -1 ? len-- : 0;
	return (len + flags.spaces_count);
}

int			ft_launch_conv_o_O(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'o')
	{
		// if (flags.length == 1 || flags.length == 2 || flags.length == 5)
		// 	return (ft_conv_o_l(*pa, flags, str + index));
		// else
			return (ft_conv_o(*pa, flags));
	}
	return (0);
}
