/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/11 19:06:49 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** s = string
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
** p = Adress
** d = int = d
** D = int in Uppercase = ld
** i = int = d
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


int		ft_printf(const char *format, ...)
{
	va_list		pa;
	int			i;

	i = 0;
	va_start(pa, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar(format[i]);
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(pa, int));
			if (format[i] == 's')
				ft_putstr(va_arg(pa, char *));
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(pa);
	return (1);
}

int		main()
{
	char	*i = "42";

	ft_printf("int = %d\n", 123);
	ft_convert_base("42", 16);
	printf("%p\n", i);
	return 0;
}