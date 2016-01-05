/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsmallest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 11:54:22 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/28 20:12:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrsmallest() function looks for the smallest number in an INT table.
*/

#include "libft.h"

int		ft_nbrsmallest(int *nbr)
{
	int		i;
	int		gr;

	i = 0;
	gr = nbr[i];
	while (nbr[i])
	{
		if (nbr[i] < gr)
			gr = nbr[i];
		i++;
	}
	return (gr);
}
