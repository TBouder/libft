/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:31:48 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:18:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putchar() function writes the character c (converted to an
** 'unsigned char') to STDIN.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
