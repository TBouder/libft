/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 04:18:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/20 18:37:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrinit() function initialize an int table with 0 (FALSE).
*/

#include "../libft.h"

void	ft_nbrinit(int *tab, size_t size)
{
	size_t		i;

	i = 0;
	while (i <= size)
	{
		tab[i] = FALSE;
		i++;
	}
}
