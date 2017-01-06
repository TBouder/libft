/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:47:06 by Tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 15:34:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_factorial() function gives us the factorial result of nb.
*/

#include "../libft.h"

double		ft_factorial(double nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1.0)
		return (nb);
	return (nb * ft_factorial(nb - 1));
}
