/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:11:40 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 23:52:03 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_spaces(char *str, int *index)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	if (ft_isnumber(str[*index]))
	{
		while (i++ < ft_atoi(&str[*index]))
			space++;
	}
	else if (str[*index] == '-')
	{
		*index += 1;
		if (ft_isnumber(str[*index]))
		{
			while (i++ < ft_atoi(&str[*index]))
				space--;
		}
	}
	*index += ft_nbrlen(ft_atoi(&str[*index]));
	return (space);
}

int		ft_flag_precision(char *str, int *index)
{
	int		value;

	value = 0;
	if (str[*index] == '.')
	{
		*index += 1;
		if (ft_isnumber(str[*index]))
		{
			value = ft_atoi(&str[*index]);
			*index += str[*index] == '0' ? 1 : ft_nbrlen(ft_atoi(&str[*index]));
		}
	}
	return (value);
}

int		ft_load_flags(char *str, int index, t_flags *flags)
{
	flags->spaces = ft_flag_spaces(str, &index);
	flags->precision = ft_flag_precision(str, &index);
	return (index);
}

int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index)
{
	t_flags		flags;

	while (ft_isspace(str[index]))
		index++;
	index = ft_load_flags(str, index, &flags); //ATTENTION ORDRE ALEATOIRE

	*r_value += str[index] == '%' ? ft_conv_percent(flags) : 0;
	*r_value += str[index] == 'd' || str[index] == 'i' ? ft_conv_d_i(*pa, flags) : 0;
	// *r_value += str[index] == 'D' ? ft_conv_S(pa) : 0;
	*r_value += str[index] == 's' ? ft_conv_s(*pa, flags) : 0;
	// *r_value += str[index] == 'S' ? ft_conv_S(pa) : 0;
	*r_value += str[index] == 'p' ? ft_conv_p(pa, flags) : 0;
	*r_value += str[index] == 'c' ? ft_conv_c(*pa, flags) : 0;
	// *r_value += str[index] == 'C' ? ft_conv_S(pa) : 0;
	*r_value += str[index] == 'o' ? ft_conv_o(*pa, flags) : 0;
	// *r_value += str[index] == 'O' ? ft_conv_S(pa) : 0;
	*r_value += str[index] == 'x' ? ft_conv_x(*pa, flags) : 0;
	*r_value += str[index] == 'X' ? ft_conv_X(*pa, flags) : 0;
	*r_value += str[index] == 'u' ? ft_conv_u(*pa, flags) : 0;
	// *r_value += str[index] == 'U' ? ft_conv_S(pa) : 0;
	*r_value -= 1;

	return (index);
}
