/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:06:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/18 14:29:35 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_flag_diaiz(int *index)
{
	*index += 1;
	return (1);
}

int		ft_flag_minus(int *index)
{
	*index += 1;
	return (1);
}

int		ft_flag_plus(int *index)
{
	*index += 1;
	return (1);
}

int		ft_flag_empty(int *index)
{
	*index += 1;
	return (1);
}

int		ft_flag_display(int *index)
{
	*index += 1;
	return (1);
}
