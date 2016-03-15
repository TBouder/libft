/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 00:53:20 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_precision_str(t_flags flags, char *local_pa, int len)
{
	int		i;

	i = 0;
	flags.spaces = 0; //to delete
	while (i < len)
	{
		ft_putchar(local_pa[i]);
		i++;;
	}
}

int		ft_conv_s(va_list pa, t_flags flags)
{
	char	*local_pa;
	int		ln;

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
		ln = (int)ft_strlen(local_pa);
		flags.precision > 0 && flags.precision < ln ? ln = flags.precision : 0;
		ft_flag_r_justified(&flags, ln);
		ft_put_precision_str(flags, local_pa, ln);
		ft_flag_l_justified(&flags, ln);
		return (ln + flags.spaces_count);
	}
}

int		ft_launch_conv_s_S(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 's')
	{
		// if (flags.length == 1 || flags.length == 2)
		// 	return (ft_conv_s_l(*pa, flags));
		// else
			return (ft_conv_s(*pa, flags));
	}
	return (0);
}
