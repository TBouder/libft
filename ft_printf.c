/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 13:29:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_undef(const char *str, int i)
{
	while (str[i])
	{
		if (ft_is_printf(str[i]) == 1 || ft_is_printf(str[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

int				ft_is_printf(char c)
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

int				ft_printf(const char *format, ...)
{
	va_list		pa;
	int			i;
	int			r_value;

	i = 0;
	r_value = 0;
	va_start(pa, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && ft_undef(format, i + 1) == 0)
			return (r_value);
		if (format[i] == '%' && format[i + 1] && ft_undef(format, i + 1))
			i = ft_printf_conv((char *)format, &pa, &r_value, i + 1);
		else if (format[i] == '%' && format[i + 1] == '\0')
			r_value--;
		else if (format[i] != '%')
			ft_putchar(format[i]);
		r_value++;
		i++;
	}
	va_end(pa);
	return (r_value);
}
