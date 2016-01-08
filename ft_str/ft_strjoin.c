/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:27 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:23:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strjoin() function appends the string s2 to the end of s1 in a new
** string str.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
			+ 1))))
			return (NULL);
		ft_strcpy(str, (char *)s1);
		return (ft_strcat(str, s2));
	}
	return (NULL);
}
