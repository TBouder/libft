/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:06:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/17 18:06:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_flag_diaiz(char *str, int *index)
{
	if (str[*index] == '#')
	{
		*index += 1;
		return (1);
	}
	return (0);
}

int		ft_flag_minus(char *str, int *index)
{
	if (str[*index] == '-')
	{
		*index += 1;
		return (1);
	}
	return (0);
}

int		ft_flag_plus(char *str, int *index)
{
	if (str[*index] == '+')
	{
		*index += 1;
		return (1);
	}
	return (0);
}

int		ft_flag_empty(char *str, int *index)
{
	if (str[*index] == ' ')
	{
		*index += 1;
		return (1);
	}
	return (0);
}
