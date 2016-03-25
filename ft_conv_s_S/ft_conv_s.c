/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 16:36:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_conv_s() function launchs the conversion for s specifier.
*/

static int	ft_conv_s_case1(char *lpa, t_flags flags)
{
	int		ln;

	ln = flags.zero;
	ft_before_str(&flags, 0);
	ft_put_precision_str(flags, lpa, -1);
	ft_after_str(&flags, 0);
	return (ln);
}

int			ft_conv_s_case2(t_flags flags)
{
	int		ln;

	ln = 6;
	ft_before_str(&flags, 6);
	(!flags.display) ? ft_putstr("(null)") : 0;
	ft_after_str(&flags, 6);
	return (ln);
}

int			ft_conv_s(va_list pa, t_flags flags)
{
	char	*local_pa;
	int		ln;

	if (flags.l == 1)
		return (ft_conv_ls(pa, flags));
	local_pa = va_arg(pa, char *);
	if (local_pa == NULL && flags.preci < 0)
		return (ft_conv_s_case1(local_pa, flags));
	else if (local_pa == NULL && flags.preci >= 0)
		return (ft_conv_s_case2(flags));
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
