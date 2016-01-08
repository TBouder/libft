/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:53:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:22:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrendl() function prints the number s followed by a \n.
*/

#include "../libft.h"

void		ft_nbrendl(int s)
{
	ft_putnbr(s);
	ft_putchar('\n');
}
