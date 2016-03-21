/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:15:26 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 19:19:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		ft_atoi_ll(const char *str)
{
	unsigned long long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str >= '0' && *str <= '1')
		result = (result + *str++ - '0') * 10;
	return (result / 10 * sign);
}
