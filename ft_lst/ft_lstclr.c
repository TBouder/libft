/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 12:09:59 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:17:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstclr() clears the list by the adress given as
** begin_list to the end.
*/

#include "../libft.h"
#include <stdlib.h>

void		ft_lstclr(t_list **begin_list)
{
	t_list	*free_list;
	t_list	*temp;

	if (begin_list != NULL)
	{
		free_list = *begin_list;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			free(temp->content);
			free(temp);
		}
		*begin_list = NULL;
	}
}
