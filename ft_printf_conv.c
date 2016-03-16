/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:11:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 16:31:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_printf(char c)
{
	if (c == '%' || c == 'd' || c == 'D' || c == 'i' || c == 'x' || c == 'X'
		|| c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'C' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == '\0')
		return (1);
	if (c == '+' || c == ' ' || c == 'z')
		return (2);
	return (0);
}

int		ft_load_flags(char *str, int index, t_flags *flags)
{
	flags->diaiz = 0;
	flags->zero = 0;
	flags->spaces = 0;
	flags->preci = 0;
	flags->length = 0;
	flags->minus = 0;
	while (ft_is_printf(str[index]) == 0)
	{
		(str[index] == '#') ? flags->diaiz = ft_flag_diaiz(str, &index) : 0;
		(str[index] == '-') ? flags->minus = ft_flag_minus(str, &index) : 0;
		(str[index] == '0') ? flags->zero = ft_flag_zero(str, &index) : 0;
		(str[index] == '.') ? flags->preci = ft_flag_preci(str, &index) : 0;
		if (str[index] > '0' && str[index] <= '9')
			flags->spaces = ft_flag_spaces(str, &index);
		if (str[index] == 'l' || str[index] == 'h' || str[index] == 'j')
			flags->length = ft_flag_length(str, &index);
	}
	if (flags->minus == 1)
	{
		if (flags->zero != 0)
		{
			flags->spaces = flags->zero;
			flags->zero = 0;
		}
		flags->spaces = -flags->spaces;
	}
	// (flags->minus == 1) ? flags->spaces = -flags->spaces : 0;
	// (flags->minus == 1) ? flags->zero = 0 : 0;
	// (flags->diaiz == 1) ? flags->spaces -= 2 : 0;

	// ft_nbrendl(flags->diaiz);
	// ft_nbrendl(flags->zero);
	// ft_nbrendl(flags->spaces);
	// ft_nbrendl(flags->preci);
	// ft_nbrendl(flags->length);
	return (index);
}

/* ----FLAGS AU DESSUS ---- */


int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index)
{
	t_flags		flags;

	while (ft_isspace(str[index]))
		index++;
	index = ft_load_flags(str, index, &flags); //ATTENTION ORDRE ALEATOIRE

	*r_value += str[index] == '%' ? ft_conv_percent(flags) : 0;
	*r_value += ft_launch_conv_d_i(pa, flags, str, index);
	*r_value += ft_launch_conv_x_X(pa, flags, str, index);
	*r_value += ft_launch_conv_u_U(pa, flags, str, index); //ADD U
	*r_value += ft_launch_conv_s_S(pa, flags, str, index); //ADD S
	*r_value += ft_launch_conv_o_O(pa, flags, str, index); //ADD O

	// *r_value += str[index] == 'D' ? ft_conv_S(pa) : 0;
	// *r_value += str[index] == 'S' ? ft_conv_S(pa) : 0;
	*r_value += str[index] == 'p' ? ft_conv_p(pa, flags, str + index) : 0;
	*r_value += str[index] == 'c' ? ft_conv_c(*pa, flags) : 0;
	// *r_value += str[index] == 'C' ? ft_conv_S(pa) : 0;
	// *r_value += str[index] == 'O' ? ft_conv_S(pa) : 0;
	// *r_value += str[index] == 'x' ? ft_conv_x(*pa, flags, str + index) : 0;
	// *r_value += str[index] == 'X' ? ft_conv_X(*pa, flags, str + index) : 0;
	// *r_value += str[index] == 'U' ? ft_conv_S(pa) : 0;
	*r_value -= 1;

	return (index);
}
