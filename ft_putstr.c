/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:40 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:22:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr() functions print the string s to STDIN.
*/

#include "libft.h"
#include <unistd.h>

void		ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
