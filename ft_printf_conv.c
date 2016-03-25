/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:11:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 17:06:57 by tbouder          ###   ########.fr       */
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

static void		ft_init_table(int (*tab[128])())
{
	tab['d'] = &ft_d_i;
	tab['i'] = &ft_d_i;
	tab['D'] = &ft_ld;
	tab['x'] = &ft_x;
	tab['X'] = &ft_lx;
	tab['u'] = &ft_u;
	tab['U'] = &ft_lu;
	tab['o'] = &ft_o;
	tab['O'] = &ft_lo;
	tab['p'] = &ft_conv_p;
	tab['s'] = &ft_conv_s;
	tab['S'] = &ft_conv_ls;
	tab['c'] = &ft_conv_c;
	tab['C'] = &ft_conv_lc;
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
	int 		(*tab[128]) (va_list, t_flags);
	t_flags		flags;

	index = ft_load_flags(str, index, &flags);
	ft_init_table(tab);
	if (ft_is_printf(str[index]) == 2)
		*r_value += ft_conv_char(flags, str[index]);
	else if (str[index] == '%')
		*r_value += ft_conv_percent(flags);
	else if (ft_is_printf(str[index]) == 1 && str[index] != '%')
		*r_value += tab[(int)str[index]](*pa, flags);
	*r_value -= 1;
	return (index);
}
