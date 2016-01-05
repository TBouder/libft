/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlargest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 11:54:15 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/28 20:13:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrlargest() function looks for the largest number in an INT table.
*/

#include "libft.h"

int		ft_nbrlargest(int *nbr)
{
	int		i;
	int		gr;

	i = 0;
	gr = 0;
	while (nbr[i])
	{
		if (nbr[i] > gr)
			gr = nbr[i];
		i++;
	}
	return (gr);
}
