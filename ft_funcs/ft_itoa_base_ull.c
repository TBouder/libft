/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:19:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 22:10:58 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itoa_base() function converts the initial int representation by a
** string pointed to by n, according to the base.
*/

#include "../ft_printf.h"

static void			ft_convert_base(unsigned long long n, int base, char *s,
						int *index)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < (unsigned long long)base)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_convert_base(n / base, base, s, index);
		ft_convert_base(n % base, base, s, index);
	}
}

char				*ft_itoa_base_ull(unsigned long long n, int base)
{
	char	*s;
	int		len;
	int		k;

	k = 0;
	len = ft_nbrlen_base(n, base);
	s = ft_strnew(len + 1);
	ft_convert_base(n, base, s, &k);
	return (s);
}
