/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:59:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/15 01:07:08 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				spaces;
	int				spaces_count;
	int				precision;
	int				zero;
}					t_flags;

int		ft_printf(const char * restrict format, ...);
int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index);

void	ft_flag_r_justified(t_flags *flags, int s_local_pa);
void	ft_flag_l_justified(t_flags *flags, int s_local_pa);
void	ft_put_precision_base(t_flags flags, long local_pa, int base, int maj);
void	ft_put_precision_str(t_flags flags, char *local_pa);


int		ft_conv_percent(t_flags flags);
int		ft_conv_d_i(va_list pa, t_flags flags);
int		ft_conv_s(va_list pa, t_flags flags);
int		ft_conv_c(va_list pa, t_flags flags);
int		ft_conv_o(va_list pa, t_flags flags);
int		ft_conv_x(va_list pa, t_flags flags);
int		ft_conv_X(va_list pa, t_flags flags);
int		ft_conv_u(va_list pa, t_flags flags);
int		ft_conv_p(va_list *pa, t_flags flags);


#endif
