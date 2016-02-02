/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:47:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/02 17:00:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_ishexa() function tests if c is a correct hexadecimal number.
*/

#include "../libft.h"

int			ft_ishexa(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}
