/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:27:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 11:46:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_conv_s(va_list pa, t_flags flags)
{
	char	*local_pa;
	int		ln;

	local_pa = va_arg(pa, char *);
	if (local_pa == NULL)
	{
		ft_before_str(&flags, 6);
		ft_putstr("(null)");
		ft_after_str(&flags, 6);
		return (6);
	}
	else
	{
		ln = ft_strlen(local_pa);
		flags.precision > 0 && flags.precision < ln ? ln = flags.precision : 0;
		ft_before_str(&flags, ln);
		ft_put_precision_str(flags, local_pa, ln);
		ft_after_str(&flags, ln);
		return (ln + flags.spaces_count);
	}
}
