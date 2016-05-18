/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:18:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 23:44:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define	O str[*index + 1]
#define	T str[*index + 2]
#define	R str[*index + 3]
#define	F str[*index + 4]

int		ft_ok(char str)
{
	if (ft_isdigit(str) || str == 'r' || str == 'g' || str == 'b' || str == 'y'
		|| str == 'p' || str == 'c' || str == 'w' || str == 'A')
		return (1);
	return (0);
}

int		ft_color(const char *str, int *index)
{
	if ((ft_ok(O) && T == '}') || (ft_ok(O) && ft_ok(T) && R == '}') || (ft_ok(O) && ft_ok(T) && ft_ok(R) == '}' && F == '}'))
	{
		ft_color_part_1(str, index);
		ft_color_part_2(str, index);
		ft_color_part_3(str, index);
		ft_color_part_4(str, index);
		ft_color_part_5(str, index);
		ft_color_part_6(str, index);
		ft_color_part_7(str, index);
		ft_color_part_8(str, index);
		ft_color_part_9(str, index);
		ft_color_part_10(str, index);
		ft_color_part_11(str, index);
		ft_color_part_12(str, index);
		if (O && T && T == '}')
			*index += 3;
		else if (O && T && R && R == '}')
			*index += 4;
		else if (O && T && R && F && F == '}')
			*index += 5;
		return (0);
	}
	else
		index += 1;
	return (1);
}
