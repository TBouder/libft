/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:23:27 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 23:04:51 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_percent(t_flags flags)
{
	ft_flag_r_justified(&flags, ft_nbrlen(1));
	ft_putchar('%');
	ft_flag_l_justified(&flags, ft_nbrlen(1));
	return (1 + flags.spaces_count);
}
