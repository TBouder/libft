/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:57:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 15:07:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_flag_spaces(char *str, int *index)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	if (str[*index] > '0' && str[*index] <= '9')
	{
		while (i++ < ft_atoi(&str[*index]))
			space++;
		*index += ft_nbrlen(ft_atoi(&str[*index]));
	}
	else if (str[*index] == '-')
	{
		*index += 1;
		if (ft_isnumber(str[*index]))
		{
			while (i++ < ft_atoi(&str[*index]))
				space--;
		}
		*index += ft_nbrlen(ft_atoi(&str[*index]));
	}
	return (space);
}

int		ft_flag_zero(char *str, int *index)
{
	int		i;
	int		zero;

	i = 0;
	zero = 0;
	if (str[*index] == '0')
	{
		*index += 1;
		while (i++ < ft_atoi(&str[*index]))
			zero++;
		*index += ft_nbrlen(ft_atoi(&str[*index]));
	}
	return (zero);
}

int		ft_flag_precision(char *str, int *index)
{
	int		value;

	value = 0;
	if (str[*index] == '.')
	{
		*index += 1;
		if (ft_isnumber(str[*index]))
		{
			value = ft_atoi(&str[*index]);
			*index += str[*index] == '0' ? 1 : ft_nbrlen(ft_atoi(&str[*index]));
		}
	}
	return (value);
}

int		ft_flag_length(char *str, int *index)
{
	str[*index] == 'l' && str[*index + 1] != 'l' ? *index += 1 : 0;
	if (str[*index] == 'l' && str[*index + 1] != 'l')
		return (1);
	str[*index] == 'l' && str[*index + 1] == 'l' ? *index += 2 : 0;
	if (str[*index] == 'l' && str[*index + 1] == 'l')
		return (2);
	str[*index] == 'h' && str[*index + 1] != 'h' ? *index += 1 : 0;
	if (str[*index] == 'h' && str[*index + 1] != 'h')
		return (3);
	str[*index] == 'h' && str[*index + 1] == 'h' ? *index += 2 : 0;
	if (str[*index] == 'h' && str[*index + 1] == 'h')
		return (4);
	str[*index] == 'j' ? *index += 1 : 0;
	if (str[*index] == 'j')
		return (5);
	return (0);
}

int		ft_flag_diaiz(char *str, int *index)
{
	if (str[*index] == '#')
	{
		*index += 1;
		return (1);
	}
	return (0);
}
