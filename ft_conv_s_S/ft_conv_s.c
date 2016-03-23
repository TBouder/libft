/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/23 13:13:42 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Convert from binary to decimal
*/

int			ft_binary_to_decimal(int b) //Add_libft
{
	char	*binary;
	int		len;
	int		i;
	int		r_value;

	len = 0;
	i = -1;
	r_value = 0;
	len = ft_nbrlen_base(b, 10);
	if (!(binary = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_memmove(binary, ft_itoa(b), len);
	while (i++ < len)
		if (binary[i] == '1')
			r_value += ft_power(2, len - i - 1);
	return (r_value);
}

/*
** Divides a unique binary in 1,2,3 or 4 parts.
*/

int			*ft_parse_binary(long long b)
{
	int		*nbr;
	int		i;

	i = 0;
	if (!(nbr = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 4)
		nbr[i++] = -1;
	if (ft_nbrlen_base(b, 10) < 8)
		nbr[0] = b;
	else if (ft_nbrlen_base(b, 10) >= 8 && ft_nbrlen_base(b, 10) <= 11)
	{
		nbr[1] = 10000000 + (b % 1000000);
		nbr[0] = 11000000 + (b / 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 12 && ft_nbrlen_base(b, 10) <= 16)
	{
		nbr[2] = 10000000 + (b % 1000000);
		nbr[1] = 10000000 + (b / 1000000 % 1000000);
		nbr[0] = 11100000 + (b / 1000000 / 1000000 % 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 17 && ft_nbrlen_base(b, 10) <= 21)
	{
		nbr[3] = 10000000 + (b % 1000000);
		nbr[2] = 10000000 + (b / 1000000 % 1000000);
		nbr[1] = 10000000 + (b / 1000000 / 1000000 % 1000000);
		nbr[0] = 11110000 + (b / 1000000 / 1000000 / 1000000 % 1000000);
	}
	return (nbr);
}


/*
** The ft_conv_s() function launchs the conversion for s specifier.
*/

int			ft_conv_s(va_list pa, t_flags flags)
{
	char	*local_pa;
	int		ln;

	local_pa = va_arg(pa, char *);
	if (local_pa == NULL && flags.preci < 0)
	{
		ln = flags.zero;
		ft_before_str(&flags, 0);
		ft_put_precision_str(flags, local_pa, -1);
		ft_after_str(&flags, 0);
		return (ln);
	}
	else if (local_pa == NULL && flags.preci >= 0)
	{
		ln = 6;
		ft_before_str(&flags, 6);
		(!flags.display) ? ft_putstr("(null)") : 0;
		ft_after_str(&flags, 6);
		return (ln);
	}
	else
	{
		ln = ft_strlen(local_pa);
		flags.preci > 0 && flags.preci < ln ? ln = flags.preci : 0;
		ft_before_str(&flags, ln);
		ft_put_precision_str(flags, local_pa, ln);
		ft_after_str(&flags, ln);
		return (ln + flags.spaces_count);
	}
	return (0);
}

/*
** The ft_conv_S() function launchs the conversion for S specifier.
*/

int			ft_wstrlen_flags(wchar_t *str, t_flags flags)
{
	int		i;
	int		len;
	int		to_add;
	char	*b;

	i = 0;
	len = 0;
	while (str[i] && len < flags.preci)
	{
		b = ft_itoa_base(str[i], 2);
		(ft_strlen(b) <= 7) ? to_add = 1 : 0;
		(ft_strlen(b) >= 8 && ft_strlen(b) <= 11) ? to_add = 2 : 0;
		(ft_strlen(b) >= 12 && ft_strlen(b) <= 16) ? to_add = 3 : 0;
		(ft_strlen(b) >= 17 && ft_strlen(b) <= 21) ? to_add = 4 : 0;
		len += to_add;
		if (len > flags.preci)
			len -= to_add;
		i++;
	}
	return (len);
}

int			ft_wstrlen(wchar_t *str)
{
	int		i;
	int		len;
	int		to_add;
	char	*b;

	i = 0;
	len = 0;
	while (str[i])
	{
		b = ft_itoa_base(str[i], 2);
		(ft_strlen(b) <= 7) ? to_add = 1 : 0;
		(ft_strlen(b) >= 8 && ft_strlen(b) <= 11) ? to_add = 2 : 0;
		(ft_strlen(b) >= 12 && ft_strlen(b) <= 16) ? to_add = 3 : 0;
		(ft_strlen(b) >= 17 && ft_strlen(b) <= 21) ? to_add = 4 : 0;
		len += to_add;
		i++;
	}
	return (len);
}


int			ft_wchar_len(int *nbr)
{
	int		i;

	i = 0;
	while (nbr[i] != -1)
		i++;
	return (i);
}

int			ft_conv_S(va_list pa, t_flags flags)
{
	wchar_t		*local_pa;
	char		*bin;
	int			*nbr;
	int			ln;
	int			lnn;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	ln = 0;
	lnn = 0;
	local_pa = (wchar_t *)va_arg(pa, char *);
	if (flags.preci == -1)
	{
		ln = flags.zero;
		ft_before_str(&flags, 0);
		ft_put_precision_str(flags, NULL, -1);
		ft_after_str(&flags, 0);
		ln = (flags.zero_base != 0) ? flags.zero_base : flags.spaces_count;
		return (ln);
	}
	else if (local_pa == NULL && flags.preci >= 0)
	{
		ln = 6;
		ft_before_str(&flags, 6);
		(!flags.display) ? ft_putstr("(null)") : 0;
		ft_after_str(&flags, 6);
		return (ln);
	}
	else if (local_pa != NULL && flags.preci == 0)
	{
		ln = flags.preci != 0 ? ft_wstrlen_flags(local_pa, flags) : ft_wstrlen(local_pa);
		ft_before_str(&flags, ln);
		while (local_pa[j])
		{
			i = 0;
			bin = ft_itoa_base(local_pa[j], 2);
			nbr = ft_parse_binary(ft_atoi_ll(bin));
			while (nbr[k] != -1)
				k++;
			while (nbr[i] != -1)
			{
				nbr[i] = ft_binary_to_decimal(nbr[i]);
				(!flags.display) ? ft_putchar(nbr[i]) : 0;
				i++;
			}
			j++;
		}
		ft_after_str(&flags, ln);
		return (ln + flags.spaces_count);
	}
	else
	{
		ln = flags.preci != 0 ? ft_wstrlen_flags(local_pa, flags) : ft_wstrlen(local_pa);
		ft_before_str(&flags, ln);
		while (local_pa[j] && lnn < flags.preci)
		{
			i = 0;
			k = 0;
			bin = ft_itoa_base(local_pa[j], 2);
			nbr = ft_parse_binary(ft_atoi_ll(bin));
			lnn += ft_wchar_len(nbr);
			while (nbr[i] != -1 && lnn <= flags.preci)
			{
				nbr[i] = ft_binary_to_decimal(nbr[i]);
				(!flags.display) ? ft_putchar(nbr[i]) : 0;
				i++;
			}
			j++;
		}
		ft_after_str(&flags, ln);
		return (ln + flags.spaces_count);
	}
	return (0);
}
