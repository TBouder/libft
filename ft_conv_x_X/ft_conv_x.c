/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:30:07 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/24 01:17:17 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_x(va_list pa, t_flags flag, int maj)
{
	char		*s;
	long long	lpa;
	long long	value;
	int			len;

	flag.l == 0 || flag.l == 3 ? lpa = va_arg(pa, int) : 0;
	flag.l != 0 && flag.l != 3 ? lpa = va_arg(pa, long long) : 0;
	if (flag.l == 0 || flag.l == 3)
	{
		value = (lpa < 0) ? 4294967296 + lpa : lpa;
		value = (lpa == 4294967296) ? 0 : value;
	}
	else if (flag.l == 4)
		value = lpa % 256;
	else
		value = lpa;
	len = ft_strlen((s = ft_itoa_base_ull(value, 16)));
	ft_before_x(&flag, ft_strlen(s), value, maj);
	ft_put_preci_hex(&flag, value, maj, flag.l);
	ft_after_hex(&flag, ft_strlen(s));
	s[0] == '0' && flag.preci == -1 ? len-- : 0;
	ft_strdel(&s);
	return (len + flag.spaces_count);
}
