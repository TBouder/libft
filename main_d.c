/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 17:58:17 by olaurent          #+#    #+#             */
/*   Updated: 2016/01/08 17:29:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <limits.h>
#include <stdarg.h>
#include "ft_printf.h"

char	g_flags[6] = "#0+- ";
int		g_is[10] = {0, 1, -1, 2147483647, -2147483648, 12, 101, 1137, 98989, -42};

char	*jjoin(int nb, char *s1, char *s2, ...)
{
	va_list		ap;
	char		*sout;
	char		*tmp;
	char		*tmp2;

	va_start(ap, s2);
	sout = ft_strjoin(s1, s2);
	nb -= 2;
	while (nb--)
	{
		tmp2 = sout;
		tmp = va_arg(ap, char *);
		sout = ft_strjoin(tmp2, tmp);
		free(tmp2);
	}
	return (sout);
}

char	*init_str(int nb, char *c, ...)
{
	va_list		ap;
	char		*sout;
	char		*tmp;
	char		*tmp2;

	va_start(ap, c);
	sout = ft_strdup("");
	while (nb--)
	{
		tmp2 = sout;
		tmp = va_arg(ap, char *);
		sout = ft_strjoin(tmp2, tmp);
		free(tmp2);
	}
	va_end(ap);
	tmp = sout;
	sout = jjoin(7, tmp, c, ":%", tmp, c, "__", "\n");
//	sout = jjoin(8, "%%", tmp, c, ":%", tmp, c, "__", "\n");
	free(tmp);
	return (sout);
}

#define N_FF 0

int		pow(int nb, int p)
{
	int		res;

	res = 1;
	while (p--)
		res *= nb;
	return (res);
}

void	do_flags(int st_f, char fl[N_FF][2])
{
	int	i;
	int	p;

	i = 0;
	while (i < N_FF)
	{
		p = pow(6, i);
		fl[i][0] = g_flags[(st_f / p) % 6 - 1];
		fl[i++][1] = 0;
	}
}

char	*next_str(char t[2])
{
	static int	st_f;
	char		fl[N_FF][2];

	if (st_f == pow(6, N_FF))
	{
		st_f = 0;
		return (NULL);
	}
	do_flags(st_f++, fl);
	if ((((st_f - 1) / 1) % 6) == 0)
		return (init_str(0, t));
	else if ((((st_f - 1) / 6) % 6) == 0)
		return (init_str(1, t, fl[0]));
	else if ((((st_f - 1) / 36) % 6) == 0)
		return (init_str(2, t, fl[0], fl[1]));
	else if ((((st_f - 1) / 216) % 6) == 0)
		return (init_str(3, t, fl[0], fl[1], fl[2]));
	else if ((((st_f - 1) / 1296) % 6) == 0)
		return (init_str(4, t, fl[0], fl[1], fl[2], fl[3]));
	else
		return (init_str(5, t, fl[0], fl[1], fl[2], fl[3], fl[4]));
}

int		main(void)
{
	int		ist;
	int		imn;
	char	*str;
	char	c = 100;
	int		d;
	short	s = 123;
//	char	types[11] = "idDxXoOuUp";
	char	types[11] = "d\0iDxXoOuUp";
	char	t[2];
	int		i;

	t[1] = 0;
	setbuf(stdout, NULL);
	i = 0;
	while (i < 1)
	{
		t[0] = types[i++];
		while ((str = next_str(t)))
		{
			d = -1;
			while (++d < 10)
			{
				ist = printf(str, g_is[d]);
				imn = ft_printf(str, g_is[d]);
				ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
			}
		}
	}
	str = init_str(0, "d");
	ist = printf(str, d);
	imn = ft_printf(str, d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s d :%d--\n", d);
	imn = ft_printf("m d :%d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one single flag */
	ist = printf("s #d :%#d--\n", d);
	imn = ft_printf("m #d :%#d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0d :%0d--\n", d);
	imn = ft_printf("m 0d :%0d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -d :%-d--\n", d);
	imn = ft_printf("m -d :%-d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  d :% d--\n", d);
	imn = ft_printf("m  d :% d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +d :%+d--\n", d);
	imn = ft_printf("m +d :%+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags */
	ist = printf("s #0d :%#0d--\n", d);
	imn = ft_printf("m #0d :%#0d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-d :%#-d--\n", d);
	imn = ft_printf("m #-d :%#-d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # d :%# d--\n", d);
	imn = ft_printf("m # d :%# d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+d :%#+d--\n", d);
	imn = ft_printf("m #+d :%#+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-d :%0-d--\n", d);
	imn = ft_printf("m 0-d :%0-d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 d :%0 d--\n", d);
	imn = ft_printf("m 0 d :%0 d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+d :%0+d--\n", d);
	imn = ft_printf("m 0+d :%0+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - d :%- d--\n", d);
	imn = ft_printf("m - d :%- d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+d :%-+d--\n", d);
	imn = ft_printf("m -+d :%-+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags */
	ist = printf("s #0-d :%#0-d--\n", d);
	imn = ft_printf("m #0-d :%#0-d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 d :%#0 d--\n", d);
	imn = ft_printf("m #0 d :%#0 d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+d :%#0+d--\n", d);
	imn = ft_printf("m #0+d :%#0+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- d :%#- d--\n", d);
	imn = ft_printf("m #- d :%#- d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+d :%#-+d--\n", d);
	imn = ft_printf("m #-+d :%#-+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- d :%0- d--\n", d);
	imn = ft_printf("m 0- d :%0- d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+d :%0-+d--\n", d);
	imn = ft_printf("m 0-+d :%0-+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags */
	ist = printf("s #0-d :%#0-d--\n", d);
	imn = ft_printf("m #0-d :%#0-d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- d :%#0- d--\n", d);
	imn = ft_printf("m #0- d :%#0- d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+d :%#0-+d--\n", d);
	imn = ft_printf("m #0-+d :%#0-+d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a width */	
	ist = printf("s 3d :%3d--\n", d);
	imn = ft_printf("m 3d :%3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #3d :%#3d--\n", d);
	imn = ft_printf("m #3d :%#3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 03d :%03d--\n", d);
	imn = ft_printf("m 03d :%03d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -3d :%-3d--\n", d);
	imn = ft_printf("m -3d :%-3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  3d :% 3d--\n", d);
	imn = ft_printf("m  3d :% 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +3d :%+3d--\n", d);
	imn = ft_printf("m +3d :%+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a width 2 */	
	ist = printf("s 5d :%5d--\n", d);
	imn = ft_printf("m 5d :%5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5d :%#5d--\n", d);
	imn = ft_printf("m #5d :%#5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05d :%05d--\n", d);
	imn = ft_printf("m 05d :%05d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5d :%-5d--\n", d);
	imn = ft_printf("m -5d :%-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5d :% 5d--\n", d);
	imn = ft_printf("m  5d :% 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5d :%+5d--\n", d);
	imn = ft_printf("m +5d :%+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a width 3 */	
	ist = printf("s 11d :%11d--\n", d);
	imn = ft_printf("m 11d :%11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #11d :%#11d--\n", d);
	imn = ft_printf("m #11d :%#11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 011d :%011d--\n", d);
	imn = ft_printf("m 011d :%011d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -11d :%-11d--\n", d);
	imn = ft_printf("m -11d :%-11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  11d :% 11d--\n", d);
	imn = ft_printf("m  11d :% 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +11d :%+11d--\n", d);
	imn = ft_printf("m +11d :%+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags and a width */
	ist = printf("s #03d :%#03d--\n", d);
	imn = ft_printf("m #03d :%#03d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-3d :%#-3d--\n", d);
	imn = ft_printf("m #-3d :%#-3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # 3d :%# 3d--\n", d);
	imn = ft_printf("m # 3d :%# 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+3d :%#+3d--\n", d);
	imn = ft_printf("m #+3d :%#+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-3d :%0-3d--\n", d);
	imn = ft_printf("m 0-3d :%0-3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 3d :%0 3d--\n", d);
	imn = ft_printf("m 0 3d :%0 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+3d :%0+3d--\n", d);
	imn = ft_printf("m 0+3d :%0+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - 3d :%- 3d--\n", d);
	imn = ft_printf("m - 3d :%- 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+3d :%-+3d--\n", d);
	imn = ft_printf("m -+3d :%-+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags and a width 2 */
	ist = printf("s #05d :%#05d--\n", d);
	imn = ft_printf("m #05d :%#05d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-5d :%#-5d--\n", d);
	imn = ft_printf("m #-5d :%#-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # 5d :%# 5d--\n", d);
	imn = ft_printf("m # 5d :%# 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+5d :%#+5d--\n", d);
	imn = ft_printf("m #+5d :%#+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-5d :%0-5d--\n", d);
	imn = ft_printf("m 0-5d :%0-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 5d :%0 5d--\n", d);
	imn = ft_printf("m 0 5d :%0 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+5d :%0+5d--\n", d);
	imn = ft_printf("m 0+5d :%0+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - 5d :%- 5d--\n", d);
	imn = ft_printf("m - 5d :%- 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+5d :%-+5d--\n", d);
	imn = ft_printf("m -+5d :%-+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags and a width 3 */
	ist = printf("s #011d :%#011d--\n", d);
	imn = ft_printf("m #011d :%#011d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-11d :%#-11d--\n", d);
	imn = ft_printf("m #-11d :%#-11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # 11d :%# 11d--\n", d);
	imn = ft_printf("m # 11d :%# 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+11d :%#+11d--\n", d);
	imn = ft_printf("m #+11d :%#+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-11d :%0-11d--\n", d);
	imn = ft_printf("m 0-11d :%0-11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 11d :%0 11d--\n", d);
	imn = ft_printf("m 0 11d :%0 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+11d :%0+11d--\n", d);
	imn = ft_printf("m 0+11d :%0+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - 11d :%- 11d--\n", d);
	imn = ft_printf("m - 11d :%- 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+11d :%-+11d--\n", d);
	imn = ft_printf("m -+11d :%-+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags and a width*/
	ist = printf("s #0-3d :%#0-3d--\n", d);
	imn = ft_printf("m #0-3d :%#0-3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 3d :%#0 3d--\n", d);
	imn = ft_printf("m #0 3d :%#0 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+3d :%#0+3d--\n", d);
	imn = ft_printf("m #0+3d :%#0+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- 3d :%#- 3d--\n", d);
	imn = ft_printf("m #- 3d :%#- 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+3d :%#-+3d--\n", d);
	imn = ft_printf("m #-+3d :%#-+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- 3d :%0- 3d--\n", d);
	imn = ft_printf("m 0- 3d :%0- 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+3d :%0-+3d--\n", d);
	imn = ft_printf("m 0-+3d :%0-+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags and a width 2 */
	ist = printf("s #0-5d :%#0-5d--\n", d);
	imn = ft_printf("m #0-5d :%#0-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 5d :%#0 5d--\n", d);
	imn = ft_printf("m #0 5d :%#0 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+5d :%#0+5d--\n", d);
	imn = ft_printf("m #0+5d :%#0+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- 5d :%#- 5d--\n", d);
	imn = ft_printf("m #- 5d :%#- 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+5d :%#-+5d--\n", d);
	imn = ft_printf("m #-+5d :%#-+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- 5d :%0- 5d--\n", d);
	imn = ft_printf("m 0- 5d :%0- 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+5d :%0-+5d--\n", d);
	imn = ft_printf("m 0-+5d :%0-+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags and a width 3 */
	ist = printf("s #0-11d :%#0-11d--\n", d);
	imn = ft_printf("m #0-11d :%#0-11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 11d :%#0 11d--\n", d);
	imn = ft_printf("m #0 11d :%#0 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+11d :%#0+11d--\n", d);
	imn = ft_printf("m #0+11d :%#0+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- 11d :%#- 11d--\n", d);
	imn = ft_printf("m #- 11d :%#- 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+11d :%#-+11d--\n", d);
	imn = ft_printf("m #-+11d :%#-+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- 11d :%0- 11d--\n", d);
	imn = ft_printf("m 0- 11d :%0- 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+11d :%0-+11d--\n", d);
	imn = ft_printf("m 0-+11d :%0-+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a width */
	ist = printf("s #0-3d :%#0-3d--\n", d);
	imn = ft_printf("m #0-3d :%#0-3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- 3d :%#0- 3d--\n", d);
	imn = ft_printf("m #0- 3d :%#0- 3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+3d :%#0-+3d--\n", d);
	imn = ft_printf("m #0-+3d :%#0-+3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a width 2 */
	ist = printf("s #0-5d :%#0-5d--\n", d);
	imn = ft_printf("m #0-5d :%#0-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- 5d :%#0- 5d--\n", d);
	imn = ft_printf("m #0- 5d :%#0- 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+5d :%#0-+5d--\n", d);
	imn = ft_printf("m #0-+5d :%#0-+5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a width 3 */
	ist = printf("s #0-11d :%#0-11d--\n", d);
	imn = ft_printf("m #0-11d :%#0-11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- 11d :%#0- 11d--\n", d);
	imn = ft_printf("m #0- 11d :%#0- 11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+11d :%#0-+11d--\n", d);
	imn = ft_printf("m #0-+11d :%#0-+11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a precision */	
	ist = printf("s .3d :%.3d--\n", d);
	imn = ft_printf("m .3d :%.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #.3d :%#.3d--\n", d);
	imn = ft_printf("m #.3d :%#.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0.3d :%0.3d--\n", d);
	imn = ft_printf("m 0.3d :%0.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -.3d :%-.3d--\n", d);
	imn = ft_printf("m -.3d :%-.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  .3d :% .3d--\n", d);
	imn = ft_printf("m  .3d :% .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +.3d :%+.3d--\n", d);
	imn = ft_printf("m +.3d :%+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a precision 2 */	
	ist = printf("s .5d :%.5d--\n", d);
	imn = ft_printf("m .5d :%.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #.5d :%#.5d--\n", d);
	imn = ft_printf("m #.5d :%#.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0.5d :%0.5d--\n", d);
	imn = ft_printf("m 0.5d :%0.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -.5d :%-.5d--\n", d);
	imn = ft_printf("m -.5d :%-.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  .5d :% .5d--\n", d);
	imn = ft_printf("m  .5d :% .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +.5d :%+.5d--\n", d);
	imn = ft_printf("m +.5d :%+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag and a precision 3 */	
	ist = printf("s .11d :%.11d--\n", d);
	imn = ft_printf("m .11d :%.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #.11d :%#.11d--\n", d);
	imn = ft_printf("m #.11d :%#.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0.11d :%0.11d--\n", d);
	imn = ft_printf("m 0.11d :%0.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -.11d :%-.11d--\n", d);
	imn = ft_printf("m -.11d :%-.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  .11d :% .11d--\n", d);
	imn = ft_printf("m  .11d :% .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +.11d :%+.11d--\n", d);
	imn = ft_printf("m +.11d :%+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags and a precision */
	ist = printf("s #0.3d :%#0.3d--\n", d);
	imn = ft_printf("m #0.3d :%#0.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-.3d :%#-.3d--\n", d);
	imn = ft_printf("m #-.3d :%#-.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # .3d :%# .3d--\n", d);
	imn = ft_printf("m # .3d :%# .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+.3d :%#+.3d--\n", d);
	imn = ft_printf("m #+.3d :%#+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-.3d :%0-.3d--\n", d);
	imn = ft_printf("m 0-.3d :%0-.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 .3d :%0 .3d--\n", d);
	imn = ft_printf("m 0 .3d :%0 .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+.3d :%0+.3d--\n", d);
	imn = ft_printf("m 0+.3d :%0+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - .3d :%- .3d--\n", d);
	imn = ft_printf("m - .3d :%- .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+.3d :%-+.3d--\n", d);
	imn = ft_printf("m -+.3d :%-+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/ 
/* All d tests with two flags and a precision 2 */
	ist = printf("s #0.5d :%#0.5d--\n", d);
	imn = ft_printf("m #0.5d :%#0.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-.5d :%#-.5d--\n", d);
	imn = ft_printf("m #-.5d :%#-.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # .5d :%# .5d--\n", d);
	imn = ft_printf("m # .5d :%# .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+.5d :%#+.5d--\n", d);
	imn = ft_printf("m #+.5d :%#+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-.5d :%0-.5d--\n", d);
	imn = ft_printf("m 0-.5d :%0-.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 .5d :%0 .5d--\n", d);
	imn = ft_printf("m 0 .5d :%0 .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+.5d :%0+.5d--\n", d);
	imn = ft_printf("m 0+.5d :%0+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - .5d :%- .5d--\n", d);
	imn = ft_printf("m - .5d :%- .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+.5d :%-+.5d--\n", d);
	imn = ft_printf("m -+.5d :%-+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/ 
/* All d tests with two flags and a precision 3 */
	ist = printf("s #0.11d :%#0.11d--\n", d);
	imn = ft_printf("m #0.11d :%#0.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-.11d :%#-.11d--\n", d);
	imn = ft_printf("m #-.11d :%#-.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # .11d :%# .11d--\n", d);
	imn = ft_printf("m # .11d :%# .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+.11d :%#+.11d--\n", d);
	imn = ft_printf("m #+.11d :%#+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-.11d :%0-.11d--\n", d);
	imn = ft_printf("m 0-.11d :%0-.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 .11d :%0 .11d--\n", d);
	imn = ft_printf("m 0 .11d :%0 .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+.11d :%0+.11d--\n", d);
	imn = ft_printf("m 0+.11d :%0+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - .11d :%- .11d--\n", d);
	imn = ft_printf("m - .11d :%- .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+.11d :%-+.11d--\n", d);
	imn = ft_printf("m -+.11d :%-+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/ 
/* All d tests with three flags and a precision */
	ist = printf("s #0-.3d :%#0-.3d--\n", d);
	imn = ft_printf("m #0-.3d :%#0-.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 .3d :%#0 .3d--\n", d);
	imn = ft_printf("m #0 .3d :%#0 .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+.3d :%#0+.3d--\n", d);
	imn = ft_printf("m #0+.3d :%#0+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- .3d :%#- .3d--\n", d);
	imn = ft_printf("m #- .3d :%#- .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+.3d :%#-+.3d--\n", d);
	imn = ft_printf("m #-+.3d :%#-+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- .3d :%0- .3d--\n", d);
	imn = ft_printf("m 0- .3d :%0- .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+.3d :%0-+.3d--\n", d);
	imn = ft_printf("m 0-+.3d :%0-+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags and a precision 2 */
	ist = printf("s #0-.5d :%#0-.5d--\n", d);
	imn = ft_printf("m #0-.5d :%#0-.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 .5d :%#0 .5d--\n", d);
	imn = ft_printf("m #0 .5d :%#0 .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+.5d :%#0+.5d--\n", d);
	imn = ft_printf("m #0+.5d :%#0+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- .5d :%#- .5d--\n", d);
	imn = ft_printf("m #- .5d :%#- .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+.5d :%#-+.5d--\n", d);
	imn = ft_printf("m #-+.5d :%#-+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- .5d :%0- .5d--\n", d);
	imn = ft_printf("m 0- .5d :%0- .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+.5d :%0-+.5d--\n", d);
	imn = ft_printf("m 0-+.5d :%0-+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with three flags and a precision 3 */
	ist = printf("s #0-.11d :%#0-.11d--\n", d);
	imn = ft_printf("m #0-.11d :%#0-.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 .11d :%#0 .11d--\n", d);
	imn = ft_printf("m #0 .11d :%#0 .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+.11d :%#0+.11d--\n", d);
	imn = ft_printf("m #0+.11d :%#0+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- .11d :%#- .11d--\n", d);
	imn = ft_printf("m #- .11d :%#- .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+.11d :%#-+.11d--\n", d);
	imn = ft_printf("m #-+.11d :%#-+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- .11d :%0- .11d--\n", d);
	imn = ft_printf("m 0- .11d :%0- .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+.11d :%0-+.11d--\n", d);
	imn = ft_printf("m 0-+.11d :%0-+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a precision */
	ist = printf("s #0-.3d :%#0-.3d--\n", d);
	imn = ft_printf("m #0-.3d :%#0-.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- .3d :%#0- .3d--\n", d);
	imn = ft_printf("m #0- .3d :%#0- .3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+.3d :%#0-+.3d--\n", d);
	imn = ft_printf("m #0-+.3d :%#0-+.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a precision 2 */
	ist = printf("s #0-.5d :%#0-.5d--\n", d);
	imn = ft_printf("m #0-.5d :%#0-.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- .5d :%#0- .5d--\n", d);
	imn = ft_printf("m #0- .5d :%#0- .5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+.5d :%#0-+.5d--\n", d);
	imn = ft_printf("m #0-+.5d :%#0-+.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags and a precision 3 */
	ist = printf("s #0-.11d :%#0-.11d--\n", d);
	imn = ft_printf("m #0-.11d :%#0-.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- .11d :%#0- .11d--\n", d);
	imn = ft_printf("m #0- .11d :%#0- .11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+.11d :%#0-+.11d--\n", d);
	imn = ft_printf("m #0-+.11d :%#0-+.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.3d :%5.3d--\n", d);
	imn = ft_printf("m 5.3d :%5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.3d :%#5.3d--\n", d);
	imn = ft_printf("m #5.3d :%#5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.3d :%05.3d--\n", d);
	imn = ft_printf("m 05.3d :%05.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.3d :%-5.3d--\n", d);
	imn = ft_printf("m -5.3d :%-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.3d :% 5.3d--\n", d);
	imn = ft_printf("m  5.3d :% 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.3d :%+5.3d--\n", d);
	imn = ft_printf("m +5.3d :%+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.5d :%5.5d--\n", d);
	imn = ft_printf("m 5.5d :%5.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.5d :%#5.5d--\n", d);
	imn = ft_printf("m #5.5d :%#5.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.5d :%05.5d--\n", d);
	imn = ft_printf("m 05.5d :%05.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.5d :%-5.5d--\n", d);
	imn = ft_printf("m -5.5d :%-5.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.5d :% 5.5d--\n", d);
	imn = ft_printf("m  5.5d :% 5.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.5d :%+5.5d--\n", d);
	imn = ft_printf("m +5.5d :%+5.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.11d :%5.11d--\n", d);
	imn = ft_printf("m 5.11d :%5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.11d :%#5.11d--\n", d);
	imn = ft_printf("m #5.11d :%#5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.11d :%05.11d--\n", d);
	imn = ft_printf("m 05.11d :%05.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.11d :%-5.11d--\n", d);
	imn = ft_printf("m -5.11d :%-5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.11d :% 5.11d--\n", d);
	imn = ft_printf("m  5.11d :% 5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.11d :%+5.11d--\n", d);
	imn = ft_printf("m +5.11d :%+5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.7d :%5.7d--\n", d);
	imn = ft_printf("m 5.7d :%5.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.7d :%#5.7d--\n", d);
	imn = ft_printf("m #5.7d :%#5.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.7d :%05.7d--\n", d);
	imn = ft_printf("m 05.7d :%05.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.7d :%-5.7d--\n", d);
	imn = ft_printf("m -5.7d :%-5.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.7d :% 5.7d--\n", d);
	imn = ft_printf("m  5.7d :% 5.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.7d :%+5.7d--\n", d);
	imn = ft_printf("m +5.7d :%+5.7d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.11d :%5.11d--\n", d);
	imn = ft_printf("m 5.11d :%5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.11d :%#5.11d--\n", d);
	imn = ft_printf("m #5.11d :%#5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.11d :%05.11d--\n", d);
	imn = ft_printf("m 05.11d :%05.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.11d :%-5.11d--\n", d);
	imn = ft_printf("m -5.11d :%-5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.11d :% 5.11d--\n", d);
	imn = ft_printf("m  5.11d :% 5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.11d :%+5.11d--\n", d);
	imn = ft_printf("m +5.11d :%+5.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 11.3d :%11.3d--\n", d);
	imn = ft_printf("m 11.3d :%11.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #11.3d :%#11.3d--\n", d);
	imn = ft_printf("m #11.3d :%#11.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 011.3d :%011.3d--\n", d);
	imn = ft_printf("m 011.3d :%011.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -11.3d :%-11.3d--\n", d);
	imn = ft_printf("m -11.3d :%-11.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  11.3d :% 11.3d--\n", d);
	imn = ft_printf("m  11.3d :% 11.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +11.3d :%+11.3d--\n", d);
	imn = ft_printf("m +11.3d :%+11.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 11.5d :%11.5d--\n", d);
	imn = ft_printf("m 11.5d :%11.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #11.5d :%#11.5d--\n", d);
	imn = ft_printf("m #11.5d :%#11.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 011.5d :%011.5d--\n", d);
	imn = ft_printf("m 011.5d :%011.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -11.5d :%-11.5d--\n", d);
	imn = ft_printf("m -11.5d :%-11.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  11.5d :% 11.5d--\n", d);
	imn = ft_printf("m  11.5d :% 11.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +11.5d :%+11.5d--\n", d);
	imn = ft_printf("m +11.5d :%+11.5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 11.11d :%11.11d--\n", d);
	imn = ft_printf("m 11.11d :%11.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #11.11d :%#11.11d--\n", d);
	imn = ft_printf("m #11.11d :%#11.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 011.11d :%011.11d--\n", d);
	imn = ft_printf("m 011.11d :%011.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -11.11d :%-11.11d--\n", d);
	imn = ft_printf("m -11.11d :%-11.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  11.11d :% 11.11d--\n", d);
	imn = ft_printf("m  11.11d :% 11.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +11.11d :%+11.11d--\n", d);
	imn = ft_printf("m +11.11d :%+11.11d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with one flag, a width and a precision */	
	ist = printf("s 5.3d :%5.3d--\n", d);
	imn = ft_printf("m 5.3d :%5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #5.3d :%#5.3d--\n", d);
	imn = ft_printf("m #5.3d :%#5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 05.3d :%05.3d--\n", d);
	imn = ft_printf("m 05.3d :%05.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.3d :%-5.3d--\n", d);
	imn = ft_printf("m -5.3d :%-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s  5.3d :% 5.3d--\n", d);
	imn = ft_printf("m  5.3d :% 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.3d :%+5.3d--\n", d);
	imn = ft_printf("m +5.3d :%+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with two flags, a width and a precision */
	ist = printf("s #05.3d :%#05.3d--\n", d);
	imn = ft_printf("m #05.3d :%#05.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-5.3d :%#-5.3d--\n", d);
	imn = ft_printf("m #-5.3d :%#-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s # 5.3d :%# 5.3d--\n", d);
	imn = ft_printf("m # 5.3d :%# 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #+5.3d :%#+5.3d--\n", d);
	imn = ft_printf("m #+5.3d :%#+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-5.3d :%0-5.3d--\n", d);
	imn = ft_printf("m 0-5.3d :%0-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0 5.3d :%0 5.3d--\n", d);
	imn = ft_printf("m 0 5.3d :%0 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+5.3d :%0+5.3d--\n", d);
	imn = ft_printf("m 0+5.3d :%0+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s - 5.3d :%- 5.3d--\n", d);
	imn = ft_printf("m - 5.3d :%- 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -+5.3d :%-+5.3d--\n", d);
	imn = ft_printf("m -+5.3d :%-+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/ 
/* All d tests with three flags, a width and a precision */
	ist = printf("s #0-5.3d :%#0-5.3d--\n", d);
	imn = ft_printf("m #0-5.3d :%#0-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0 5.3d :%#0 5.3d--\n", d);
	imn = ft_printf("m #0 5.3d :%#0 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0+5.3d :%#0+5.3d--\n", d);
	imn = ft_printf("m #0+5.3d :%#0+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #- 5.3d :%#- 5.3d--\n", d);
	imn = ft_printf("m #- 5.3d :%#- 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #-+5.3d :%#-+5.3d--\n", d);
	imn = ft_printf("m #-+5.3d :%#-+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0- 5.3d :%0- 5.3d--\n", d);
	imn = ft_printf("m 0- 5.3d :%0- 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0-+5.3d :%0-+5.3d--\n", d);
	imn = ft_printf("m 0-+5.3d :%0-+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
/* All d tests with four flags, a width and a precision */
	ist = printf("s #0-5.3d :%#0-5.3d--\n", d);
	imn = ft_printf("m #0-5.3d :%#0-5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0- 5.3d :%#0- 5.3d--\n", d);
	imn = ft_printf("m #0- 5.3d :%#0- 5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s #0-+5.3d :%#0-+5.3d--\n", d);
	imn = ft_printf("m #0-+5.3d :%#0-+5.3d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
////
	ist = printf("s - 5d :%- 5d--\n", d);
	imn = ft_printf("m - 5d :%- 5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5d :%-5d--\n", d);
	imn = ft_printf("m -5d :%-5d--\n", d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 0+5d :%0+5d--\n", -d);
	imn = ft_printf("m 0+5d :%0+5d--\n", -d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s +5.4d :%0+5.4d--\n", -d);
	imn = ft_printf("m +5.4d :%0+5.4d--\n", -d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s -5.4d :%-5.4d--\n", -d);
	imn = ft_printf("m -5.4d :%-5.4d--\n", -d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s d -5.2 :%-5.2d--\n", -d);
	imn = ft_printf("m d -5.2 :%-5.2d--\n", -d);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s hd :%hd--\n", s);
	imn = ft_printf("m hd :%hd--\n", s);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");

	ist = printf("zd :%zd--\n", 2147483649);
	imn = ft_printf("zd :%zd--\n", 2147483649);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s hhd :%hhd--\n", c);
	imn = ft_printf("m hhd :%hhd--\n", c);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s 5+.3+hh d :%5+.3+hh d--\n", c);
	imn = ft_printf("m 5+.3+hh d :%5+.3+hh d--\n", c);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s %%.d :%.d--\n", 42);
	imn = ft_printf("s %%.d :%.d--\n", 42);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	ist = printf("s %%hhjhd :%hhjhd--\n", -4147483649);
	imn = ft_printf("s %%hhjhd :%hhjhd--\n", -4147483649);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
	str = ft_strdup("s %%mddd :%mddd--\n");
	ist = printf(str, 42);
	imn = ft_printf(str, 42);
	ft_putstr((ist != imn) ? "OUT IS BAD\n" : "ok\n");
//*/
//	str = init_str(3, "d", ".5", "hh", "6");
//	ft_putstr(str);
	return (0);
}
