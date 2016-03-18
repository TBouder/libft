/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:11:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 14:29:58 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_printf(char c)
{
	if (c == '%' || c == 'd' || c == 'D' || c == 'i' || c == 'x' || c == 'X'
		|| c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'C' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U')
		return (1);
	if (c == '.' || ft_isnumber(c) || c == '#' || c == '-' || c == '+'
		|| c == ' ' || c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == '!')
		return (0);
	return (2);
}

int		ft_load_flags(char *str, int index, t_flags *flag)
{
	flag->diaiz = 0;
	flag->zero = 0;
	flag->spaces = 0;
	flag->preci = 0;
	flag->length = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->empty = 0;
	flag->spaces_count = 0;
	flag->preci_diff = 0;
	flag->display = 0;
	while (ft_is_printf(str[index]) == 0)
	{
		(str[index] == '#') ? flag->diaiz = ft_flag_diaiz(&index) : 0;
		(str[index] == '-') ? flag->minus = ft_flag_minus(&index) : 0;
		(str[index] == '.') ? flag->preci = ft_flag_preci(str, &index) : 0;
		(str[index] == ' ') ? flag->empty = ft_flag_empty(&index) : 0;
		(str[index] == '+') ? flag->plus = ft_flag_plus(&index) : 0;
		(str[index] == '0') ? flag->zero = ft_flag_zero(str, &index, flag) : 0;
		(str[index] == '!') ? flag->display = ft_flag_display(&index) : 0;
		if (str[index] > '0' && str[index] <= '9')
			flag->spaces = ft_flag_spaces(str, &index);
		if (str[index] == 'l' || str[index] == 'h' || str[index] == 'j' || str[index] == 'z')
			flag->length = ft_flag_length(str, &index);
	}
	if (flag->minus == 1)
	{
		if (flag->zero != 0)
		{
			flag->spaces = flag->zero;
			flag->zero = 0;
		}
		flag->spaces = -flag->spaces;
	}
	if (flag->preci != 0 && flag->zero != 0)
	{
		flag->spaces = flag->zero;
		flag->zero = 0;
	}
	(flag->plus == 1 && flag->empty == 1) ? flag->empty = 0 : 0;

	return (index);
}

/* ----FLAGS AU DESSUS ---- */


int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index)
{
	t_flags		flags;

	index = ft_load_flags(str, index, &flags);

	if (str[index] == '\0')
	{
		*r_value -= 1;
		return (index + 1);
	}
	*r_value += str[index] == '%' ? ft_conv_percent(flags) : 0;
	*r_value += ft_launch_conv_d_i(pa, flags, str, index); //ADD D
	*r_value += ft_launch_conv_x_X(pa, flags, str, index);
	*r_value += ft_launch_conv_u_U(pa, flags, str, index);
	*r_value += ft_launch_conv_s_S(pa, flags, str, index); //ADD S
	*r_value += ft_launch_conv_o_O(pa, flags, str, index);

	*r_value += str[index] == 'p' ? ft_conv_p(pa, flags, str + index) : 0;
	*r_value += str[index] == 'c' ? ft_conv_c(*pa, flags) : 0;
	*r_value += str[index] == 'C' ? ft_conv_c(*pa, flags) : 0;
	*r_value -= 1;

	if (ft_is_printf(str[index]) == 2)
		*r_value += ft_conv_char(flags, str[index]);

	return (index);
}
