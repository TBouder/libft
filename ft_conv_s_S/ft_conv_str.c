/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 11:47:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_precision_str(t_flags flags, char *local_pa, int len)
{
	int		i;

	i = 0;
	flags.spaces = 0; //to delete
	while (i < len)
	{
		ft_putchar(local_pa[i]);
		i++;;
	}
}

void	ft_before_str(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - s_local_pa > 0)
	{
		while (flags->spaces - s_local_pa != 0)
		{
			flags->spaces--;
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

void	ft_after_str(t_flags *flags, int s_local_pa)
{
	int		i;

	i = 0;
	if (flags->spaces + s_local_pa < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + s_local_pa != 0)
		{
			flags->spaces_count++;
			ft_putchar(' ');
		}
	}
}

int			ft_launch_conv_s_S(va_list *pa, t_flags flags, char *str, int index)
{
	if (str[index] == 's')
	{
		return (ft_conv_s(*pa, flags));
	}
	return (0);
}
