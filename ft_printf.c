/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 17:30:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int somme(const char *n1, ...) //n1 est le premier truc : somme(2,3,5,7,9,0) => c'est le 2
{
	va_list		pa;
	int			som;
	int			n;

	som = 0;
	va_start(pa, n1);
	while((n = va_arg(pa, int)) != 0)
		som++;
	va_end(pa);
	return (som);
} 

int		ft_printf(const char *format, ...)
{
	va_list		pa;
	char		*f;

	f = ft_strnew(ft_strlen(format) + 1);
	ft_strcpy(f, format);

	va_start(pa, format);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (*f == 'd')
				ft_putnbr(va_arg(pa, int));
		}
		else
			ft_putchar(*f);
		f++;
	}
	va_end(pa);
	return (1);
}

/*int		main()
{
	printf("coucou : %4");
	ft_printf("int = %d\n", 123);
	return 0;
}*/