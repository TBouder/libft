/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:59:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 11:44:57 by tbouder          ###   ########.fr       */
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
	int				length;
	int				diaiz;
}					t_flags;

int		ft_printf(const char * restrict format, ...);
int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index);

/*Tools*/
void	ft_flag_r_justified(t_flags *flags, int s_local_pa);
void	ft_flag_l_justified(t_flags *flags, int s_local_pa);
void	ft_put_precision(t_flags flags, long long local_pa, int base, int maj);

/*Flags*/
int		ft_flag_spaces(char *str, int *index);
int		ft_flag_zero(char *str, int *index);
int		ft_flag_precision(char *str, int *index);
int		ft_flag_length(char *str, int *index);
int		ft_flag_diaiz(char *str, int *index);


int		ft_conv_percent(t_flags flags);

/*i & d*/
int		ft_launch_conv_d_i(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_d_i(va_list pa, t_flags flags, char *str);
int		ft_conv_d_i_l(va_list pa, t_flags flags, char *str);
int		ft_conv_d_i_ll(va_list pa, t_flags flags, char *str);

/*x & X*/
void	ft_put_preci_hex(t_flags flags, long long local_pa, int base, int maj);
void	ft_put_preci_hex_ll(t_flags flags, long long local_pa, int maj);
void	ft_before_hex(t_flags *flags, int s_local_pa, long long value, int maj);
void	ft_after_hex(t_flags *flags, int s_local_pa);
int		ft_launch_conv_x_X(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_x(va_list pa, t_flags flags, char *str);
int		ft_conv_x_l(va_list pa, t_flags flags, char *str);
int		ft_conv_X(va_list pa, t_flags flags, char *str);
int		ft_conv_X_l(va_list pa, t_flags flags, char *str);

/*u & U*/
int		ft_launch_conv_u_U(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_u(va_list pa, t_flags flags);

/*s & S*/
void	ft_put_precision_str(t_flags flags, char *local_pa, int len);
void	ft_before_str(t_flags *flags, int s_local_pa);
void	ft_after_str(t_flags *flags, int s_local_pa);
int		ft_launch_conv_s_S(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_s(va_list pa, t_flags flags);

int		ft_conv_c(va_list pa, t_flags flags);
int		ft_conv_o(va_list pa, t_flags flags, char *str);
int		ft_conv_p(va_list *pa, t_flags flags, char *str);


#endif
