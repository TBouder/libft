/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:22:47 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr_fd() function print the string s to the output stream
** pointed to by fd.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
