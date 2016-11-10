/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:11:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/10 11:37:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_btreedel() function remove and free the current tree.
*/

#include "../libft.h"

void ft_btreedel(t_btree *tree)
{
	if (tree)
	{
		ft_btreedel(tree->left);
		ft_btreedel(tree->right);
		free(tree->content);
		free(tree);
	}
}
