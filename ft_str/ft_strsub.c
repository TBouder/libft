/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:07:03 by tbouder           #+#    #+#             */
/*   Updated: 2015/11/28 16:06:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (s == NULL || !(buffer = ft_strnew(len)) || len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		buffer[i] = ((char *)s)[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}
