/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 11:07:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_s(va_list pa, t_flags flags, char *str)
{
	char	*local_pa;
	int		len;
	int		space;

	space = 0;
	if (str[-1] == ' ')
	{
		ft_putchar(' ');
		space = 1;
	}
	local_pa = va_arg(pa, char *);
	if (local_pa == NULL)
	{
		ft_flag_r_justified(&flags, 6);
		ft_putstr("(null)");
		ft_flag_l_justified(&flags, 6);
		return (6);
	}
	else
	{
		len = flags.precision < (int)ft_strlen(local_pa) ? flags.precision
			: (int)ft_strlen(local_pa);
		ft_flag_r_justified(&flags, len);
		ft_put_precision_str(flags, local_pa);
		ft_flag_l_justified(&flags, len);
		return (len + flags.spaces_count + space);
	}
}
