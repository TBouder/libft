/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 19:35:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int			ft_conv_S(va_list pa, t_flags flags)
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
