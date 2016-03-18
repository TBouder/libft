/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 14:56:47 by Tbouder          ###   ########.fr       */
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
	if (local_pa == NULL)
	{
		ft_before_str(&flags, 6);
		(!flags.display) ? ft_putstr("(null)") : 0;
		ft_after_str(&flags, 6);
		return (6);
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
}
