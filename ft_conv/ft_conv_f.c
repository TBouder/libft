/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:16:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 21:46:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putfloat(double nb, int preci, t_flags flags)
{
	long long		flt;
	long long		tmp;

	ft_putnbr_ll((long) nb);
	flt = (nb - (long)nb) * ft_power(10, preci);
	if (nb > (long)nb && preci > 0)
	{
		ft_putchar('.');
		tmp = (nb - (long)nb) * ft_power(10, preci + 1);
		if (tmp % 10 >= 5)
			flt += 1;
		ft_putnbr_ll(flt);
	}
	else if (flags.diaiz)
		ft_putchar('.');
	else if (flt == 0 && preci > 0)
	{
		ft_putchar('.');
		while (preci--)
			ft_putchar('0');
	}
}

int		ft_f_helper(t_flags flag, double lpa, int sign, int space)
{
	int		prec;
	int		len;

	prec = (flag.preci <= 0) ? 1 : 0;
	len = ft_nbrlen_ll(lpa) + space + prec;
	ft_before_f(&flag, len + 6 + 1, lpa);
	(sign == 1) ? ft_putchar('-') : 0;
	(!flag.display) ? ft_putfloat(lpa, 6, flag) : 0;
	ft_after_f(&flag, len + 6 + 1 - prec + sign);
	return (len + 6 + 1 + flag.spaces_count + sign + space - prec);
}


int		ft_f(va_list pa, t_flags flag)
{
	double		lpa;
	int			space;
	int			len;
	int			sign;
	int			prec;

	lpa = va_arg(pa, double);
	(flag.empty == 1 && lpa > 0 && (!flag.display)) ? ft_putchar(' ') : 0;
	space = (flag.empty == 1) && (lpa > 0) ? 1 : 0;
	sign = (lpa < 0) ? 1 : 0;
	(sign == 1) ? lpa = -lpa : 0;
	prec = (flag.preci <= 0) ? 1 : 0;
	len = ft_nbrlen_ll(lpa) + space + prec;
	if (flag.preci != 0)
	{
		ft_before_f(&flag, len + flag.preci + 1 - prec + sign, lpa);
		(sign == 1) ? ft_putchar('-') : 0;
		(!flag.display) ? ft_putfloat(lpa, flag.preci, flag) : 0;
		ft_after_f(&flag, len + flag.preci + 1 - prec + sign);
		return (len + flag.preci + 1 + flag.spaces_count + sign + space - prec);
	}
	else
		return (ft_f_helper(flag, lpa, sign, space));
}
