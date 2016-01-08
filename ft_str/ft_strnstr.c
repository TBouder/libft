/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:05:56 by tbouder           #+#    #+#             */
/*   Updated: 2015/11/28 16:06:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = 0;
	if (s2 == NULL)
		return ((char *)s1);
	while (s1 && (i <= n && i <= ft_strlen(s1)))
	{
		j = 0;
		match = 0;
		while (s1[i] == s2[j] && s1[i] && s2[j] && i < n)
		{
			i++;
			j++;
			match++;
		}
		if (match == ft_strlen(s2))
			return ((char *)s1 + i - match);
		else
			i -= match;
		i++;
	}
	return (NULL);
}
