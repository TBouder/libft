/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:00:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 11:30:00 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

static int	ft_conv_ws_case1(t_flags flags)
{
	int		ln;

	ln = flags.zero;
	ft_before_str(&flags, 0);
	ft_put_precision_str(flags, NULL, -1);
	ft_after_str(&flags, 0);
	ln = (flags.zero_base != 0) ? flags.zero_base : flags.spaces_count;
	return (ln);
}

static int	ft_conv_ws_case3(t_flags flags, wchar_t *lpa)
{
	int		j;
	int		i;
	int		ln;
	char	*bin;
	int		*nbr;

	i = 0;
	ln = flags.preci != 0 ? ft_wstrlen_flags(lpa, flags) : ft_wstrlen(lpa);
	ft_before_str(&flags, ln);
	while (lpa[i])
	{
		j = 0;
		bin = ft_itoa_base(lpa[i], 2);
		nbr = ft_parse_binary(ft_atoi_ll(bin));
		while (nbr[j] != -1)
		{
			nbr[j] = ft_binary_to_decimal(nbr[j]);
			(!flags.display) ? ft_putchar(nbr[j]) : 0;
			j++;
		}
		i++;
	}
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}

static int	ft_conv_ws_case4(t_flags flags, wchar_t *lpa, int i)
{
	int		j;
	int		ln;
	int		lnn;
	char	*bin;
	int		*nbr;

	ln = flags.preci != 0 ? ft_wstrlen_flags(lpa, flags) : ft_wstrlen(lpa);
	lnn = 0;
	ft_before_str(&flags, ln);
	while (lpa[i] && lnn < flags.preci)
	{
		j = 0;
		bin = ft_itoa_base(lpa[i], 2);
		nbr = ft_parse_binary(ft_atoi_ll(bin));
		lnn += ft_wchar_len(nbr);
		while (nbr[j] != -1 && lnn <= flags.preci)
		{
			nbr[j] = ft_binary_to_decimal(nbr[j]);
			(!flags.display) ? ft_putchar(nbr[j]) : 0;
			j++;
		}
		i++;
	}
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}

int			ft_conv_S(va_list pa, t_flags flags)
{
	wchar_t		*local_pa;

	local_pa = (wchar_t *)va_arg(pa, char *);
	if (flags.preci == -1)
		return (ft_conv_ws_case1(flags));
	else if (local_pa == NULL && flags.preci >= 0)
		return (ft_conv_s_case2(flags));
	else if (local_pa != NULL && flags.preci == 0)
		return (ft_conv_ws_case3(flags, local_pa));
	else
		return (ft_conv_ws_case4(flags, local_pa, 0));
}
