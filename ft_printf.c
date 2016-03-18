/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 13:41:24 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//SDOUC
/*
** S = l'argument de type const wchar_t * est supposé être un pointeur sur un tableau de caractères
		larges. Les caractères larges du tableau sont convertis en une séquence de caractères multi-octets
		(chacun par un appel de wcrtomb(3), avec un état de conversion dans l'état initial avant le premier
		caractère large), ceci jusqu'au caractère large nul final compris. Les caractères multi-octets
		résultants sont écris jusqu'à l'octet nul final (non compris). Si une précision est fournie, il
		n'y a pas plus d'octets écrits que la précision indiquée, mais aucun caractère multi-octet n'est
		écrit partiellement. Remarquez que la précision concerne le nombre d'octets écrits, et non pas le
		nombre de caractères larges ou de positions d'écrans. La chaîne doit contenir un caractère large nul
		final, sauf si une précision est indiquée, suffisamment petite pour que le nombre d'octets écrits la
		remplisse avant la fin de la chaîne.
** D = int in Uppercase = ld
** o = unsigned octal (conversion en octal)
** O = unsigned octal (conversion en octal) Uppercase = lo
** u = unsigned decimal (Conversion en decimal)
** U = unsigned decimal (Conversion en decimal) Uppercase = lu
** x = unsigned hexadecimal - 123456789abcdef
** X = unsigned hexadecimal - 123456789ABCDEF
** c = l'argument entier, de type int, est converti en un unsigned char, et le caractère correspondant est affiché (affiche caractere)
** C = l'argument de type wint_t (caractère large) est converti en séquence multi-octet par un appel à wcrtomb(3), avec un état
** 		de conversion débutant dans l'état initial. La chaîne multi-octet résultante est écrite.
*/


int		ft_undef(const char *str, int i)
{
	int		j;

	j = 0;
	while (str[i])
	{
		if (ft_is_printf(str[i]) == 1 || ft_is_printf(str[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		pa;
	int			i;
	int			r_value;

	i = 0;
	r_value = 0;
	va_start(pa, format);
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
