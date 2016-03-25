/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:11:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 14:58:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_flags(t_flags *flag)
{
	flag->diaiz = 0;
	flag->zero = 0;
	flag->spaces = 0;
	flag->preci = 0;
	flag->l = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->empty = 0;
	flag->spaces_count = 0;
	flag->preci_diff = 0;
	flag->display = 0;
	flag->temp = 0;
}

static int		ft_load_flags(char *str, int index, t_flags *flag)
{
	ft_init_flags(flag);
	while (ft_is_printf(str[index]) == 0)
	{
		(str[index] == '#') ? flag->diaiz = ft_flag_bool(&index) : 0;
		(str[index] == '-') ? flag->minus = ft_flag_bool(&index) : 0;
		(str[index] == '.') ? flag->preci = ft_flag_preci(str, &index) : 0;
		(str[index] == ' ') ? flag->empty = ft_flag_bool(&index) : 0;
		(str[index] == '+') ? flag->plus = ft_flag_bool(&index) : 0;
		(str[index] == '0') ? flag->zero = ft_flag_zero(str, &index, flag) : 0;
		(str[index] == '!') ? flag->display = ft_flag_bool(&index) : 0;
		if (str[index] > '0' && str[index] <= '9')
			flag->spaces = ft_flag_spaces(str, &index);
		if (str[index] == 'l' || str[index] == 'h' || str[index] == 'j'
			|| str[index] == 'z')
			flag->l = ft_flag_length(str, &index, *flag);
	}
	flag->zero_base = flag->zero;
	(flag->minus == 1 && flag->zero != 0) ? flag->spaces = flag->zero : 0;
	(flag->minus == 1 && flag->zero != 0) ? flag->zero = 0 : 0;
	(flag->minus == 1) ? flag->spaces = -flag->spaces : 0;
	(flag->plus == 1 && flag->empty == 1) ? flag->empty = 0 : 0;
	return (index);
}

int				ft_printf_conv(char *str, va_list *pa, int *r_value, int index)
{
	t_flags		flags;

	index = ft_load_flags(str, index, &flags);
	if (str[index] == '\0')
	{
		*r_value -= 1;
		return (index + 1);
	}
	*r_value += str[index] == '%' ? ft_conv_percent(flags) : 0;
	*r_value += ft_launch_conv_d_i(pa, flags, str, index);
	*r_value += ft_launch_conv_x(pa, flags, str, index);
	*r_value += ft_launch_conv_u(pa, flags, str, index);
	*r_value += ft_launch_conv_s(pa, flags, str, index);
	*r_value += ft_launch_conv_c(pa, flags, str, index);
	*r_value += ft_launch_conv_o(pa, flags, str, index);
	*r_value += str[index] == 'p' ? ft_conv_p(pa, flags) : 0;
	*r_value -= 1;
	if (ft_is_printf(str[index]) == 2)
		*r_value += ft_conv_char(flags, str[index]);
	return (index);
}
