/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:18:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 20:15:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define	O str[*index + 1]
#define	T str[*index + 2]
#define	R str[*index + 3]
#define	F str[*index + 4]

int		ft_color(const char *str, int *index)
{
	if (O < '0' && O > '9' && O != 'r' && O != 'g' && O != 'y' && O != 'b'
		&& O != 'p' && O != 'c' && O != 'w' && O != 'A')
	{
		index += 1;
		return (1);
	}
	else
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
		T == '}' ? *index += 3 : 0;
		R == '}' ? *index += 4 : 0;
		F == '}' ? *index += 5 : 0;
		return (0);
	}
}
