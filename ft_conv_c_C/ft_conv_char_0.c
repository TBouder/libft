/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:39:27 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/22 18:03:30 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_c() add spaces before if needed //RISQUE DE CHANGER.
*/

void	ft_before_c(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces - v_len != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
	else if (flags->zero_base && flags->zero_base - v_len > 0)
	{
		while (flags->zero_base-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

/*
** The ft_after_c() function adds spaces after the output when the conditions
** are met.
*/

void	ft_after_c(t_flags *flags, int v_len)
{
	int		i;

	i = 0;
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

/*
** The ft_launch_conv_c_C() function launchs the conversion by c or C.
*/

int		ft_launch_conv_c_C(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 'c' && flags.length != 1)
	{
		return (ft_conv_c(*pa, flags));
	}
	if (str[index] == 'C' || (str[index] == 'c' && flags.length == 1))
	{
		return (ft_conv_C(*pa, flags));
	}
	return (0);
}
