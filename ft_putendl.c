/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:20 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:23:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl() functions print the string s to STDIN followed by a \n.
*/

#include "libft.h"

void		ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
