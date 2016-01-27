/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/09 16:40:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr() function prints the string s to STDIN.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
