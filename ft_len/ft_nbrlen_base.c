/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:06:30 by Tbouder           #+#    #+#             */
/*   Updated: 2016/06/02 12:16:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrlen_base() function computes the length of nbr, according to the
** base. TO DO : add bases after 10.
*/

#include "../libft.h"

int		ft_nbrlen_base(long value, int base)
{
	int		result;

	result = 0;
	if (value == 0)
		return (2);
	while (value != 0)
	{
		result++;
		value /= base;
	}
	return (result + 1);
}
