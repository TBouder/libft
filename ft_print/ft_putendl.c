/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:45 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 15:55:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl() function prints the string str to the output stream
** pointed to by fd followed by a \n.
*/

#include "../libft.h"

void		ft_putendl(char const *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
