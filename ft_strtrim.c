/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:07:14 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/03 15:36:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_spaces_st(char const *s)
{
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	while (ft_isspace(s[i]))
	{
		i++;
		spaces++;
	}
	return (spaces);
}

static int		count_spaces_nd(char const *s)
{
	int		j;
	int		spaces;

	j = 1;
	spaces = 0;
	while (ft_isspace(s[ft_strlen(s) - j]))
	{
		j++;
		spaces++;
	}
	return (spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		spaces;

	if (s == NULL)
		return (NULL);
	spaces = count_spaces_st(s) + count_spaces_nd(s);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) - spaces);
	str = ft_strsub(s, count_spaces_st(s), ft_strlen(s) - count_spaces_nd(s));
	str[ft_strlen(s) - spaces] = '\0';
	return (str);
}
