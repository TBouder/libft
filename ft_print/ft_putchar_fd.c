/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:04 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:19:05 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putchar() function writes the character c (converted to an
** 'unsigned char') to the output stream pointed to by fd.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
