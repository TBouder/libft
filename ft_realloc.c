/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:21:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/04 11:36:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_realloc() function tries to change the size of the allocation
** pointed to by ptr to size, and returns ptr. If ptr is NULL, ft_realloc()
** is identical to a call to malloc() for size bytes.
*/

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*temp;

	temp = ft_memalloc(size);
	if (ptr)
	{
		if (temp)
			ft_memcpy(temp, ptr, size);
		ft_memdel(&ptr);
	}
	return (temp);
}
