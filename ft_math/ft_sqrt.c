/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:48:38 by Tbouder           #+#    #+#             */
/*   Updated: 2016/01/30 19:55:12 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_sqrt() function returns the square of nb.
*/

#include "../libft.h"

int		ft_sqrt(int nb)
{
	int		base;

	base = 1;
	while ((base * base) < nb)
		base++;
	if ((base * base) == nb)
		return (base);
	else
		return (0);
}
