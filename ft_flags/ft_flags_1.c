/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:06:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 13:28:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_l_helper_0(int *index)
{
	*index += 1;
	return (1);
}

static int	ft_flag_l_helper_1(int *index)
{
	*index += 2;
	return (2);
}

static int	ft_flag_l_helper_2(int *index)
{
	*index += 1;
	return (3);
}

int			ft_flag_length(char *str, int *index)
{
	if (str[*index] == 'l' && str[*index + 1] != 'l')
		return (ft_flag_l_helper_0(index));
	if (str[*index] == 'l' && str[*index + 1] == 'l')
		return (ft_flag_l_helper_1(index));
	if (str[*index] == 'h' && str[*index + 1] != 'h')
		return (ft_flag_l_helper_2(index));
	if (str[*index] == 'h' && str[*index + 1] == 'h')
	{
		*index += 2;
		return (4);
	}
	if (str[*index] == 'j')
	{
		*index += 1;
		return (5);
	}
	if (str[*index] == 'z')
	{
		*index += 1;
		return (6);
	}
	return (0);
}
