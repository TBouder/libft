/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 19:35:21 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 16:00:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_o_spaces() functions adds spaces before the output when
** the conditions are met.
*/

static void		ft_before_o_spaces(t_flags *flags, int v_len,
					long long local_pa)
{
	(flags->diaiz == 1) ? flags->spaces-- : 0;
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	while (flags->spaces-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar(' ') : 0;
	}
	if (flags->preci == -1 && local_pa == 0 && (!flags->display))
		ft_putchar(' ');
	(flags->preci == -1) && (local_pa == 0) ? flags->spaces_count++ : 0;
}

/*
** The ft_before_o_zero() functions adds zeros before the output when
** the conditions are met.
*/

static void		ft_before_o_zero(t_flags *flags, int v_len)
{
	(flags->diaiz == 1) ? flags->zero-- : 0;
	(flags->diaiz == 1) && (!flags->display) ? ft_putstr("0") : 0;
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar('0') : 0;
	}
}

/*
** The ft_before_o() function is a launcher for the two functions above.
*/

void			ft_before_o(t_flags *flags, int v_len, int index,
					long long local_pa)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_o_spaces(flags, v_len, local_pa);
	else if (flags->zero && flags->zero - v_len > 0)
	{
		ft_before_o_zero(flags, v_len);
		index = 1;
	}
	if (index == 0 && flags->diaiz == 1)
	{
		if (flags->preci == -1 || (flags->preci == 0 && local_pa != 0))
			(!flags->display) ? ft_putstr("0") : 0;
		else if (local_pa == 0)
			flags->diaiz = 0;
		else if (local_pa > 0 && flags->diaiz)
			(!flags->display) ? ft_putstr("0") : 0;
	}
	(flags->diaiz == 1) ? flags->spaces_count++ : 0;
}

/*
** The ft_after_o() function adds spaces after the output when the conditions
** are met.
*/

void			ft_after_o(t_flags *flags, int v_len)
{
	(flags->preci == -1) ? flags->spaces-- : 0;
	(flags->diaiz) ? flags->spaces++ : 0;
	if (flags->spaces + v_len + flags->preci_diff < 0)
	{
		while (flags->spaces + v_len + flags->preci_diff < 0)
		{
			flags->spaces++;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

/*
** The ft_launch_conv_o_O() function launchs the conversion by o or O.
*/

int				ft_launch_conv_o_O(va_list *pa, t_flags flags, char *str,
					int index)
{
	if (str[index] == 'o')
	{
		if (flags.length == 1 || flags.length == 2)
			return (ft_conv_o_ll(*pa, flags));
		else if (flags.length == 3)
			return (ft_conv_o_h(*pa, flags));
		else if (flags.length == 4)
			return (ft_conv_o_hh(*pa, flags));
		else if (flags.length == 5)
			return (ft_conv_o_j(*pa, flags));
		else if (flags.length == 6)
			return (ft_conv_o_z(*pa, flags));
		else
			return (ft_conv_o(*pa, flags));
	}
	else if (str[index] == 'O')
	{
		if (flags.length == 1 || flags.length == 2 || flags.length == 3 || flags.length == 4)
			return (ft_conv_o_ll(*pa, flags));
		else if (flags.length == 5)
			return (ft_conv_o_j(*pa, flags));
		else if (flags.length == 6)
			return (ft_conv_o_z(*pa, flags));
		else
			return (ft_conv_O(*pa, flags));
	}
	return (0);
}
