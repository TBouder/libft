/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 18:37:06 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_s(va_list pa, t_flags flags)
{
	char	*local_pa;

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
		ft_flag_r_justified(&flags, ft_strlen(local_pa));
		ft_putstr(local_pa);
		ft_flag_l_justified(&flags, ft_strlen(local_pa));
		return (ft_strlen(local_pa) + flags.spaces_count);
	}
}
