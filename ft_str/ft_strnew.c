/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:54:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:23:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnew() function malloc a char buffer and use the ft_bzero()
** function to initialize it.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(buffer, size + 1);
	return (buffer);
}
