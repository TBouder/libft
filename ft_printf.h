/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:59:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 12:02:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h> // ?
# include "libft/libft.h"

typedef struct		s_flags
{
	int				spaces;
	int				spaces_count;
	int				preci;
	int				preci_diff;
	int				zero;
	int				zero_base;
	int				length;
	int				diaiz;
	int				minus;
	int				plus;
	int				empty;
	int				display;
}					t_flags;

int		ft_printf(const char * restrict format, ...);
int		ft_printf_conv(char *str, va_list *pa, int *r_value, int index);
int		ft_is_printf(char c);

/*Tools*/
void	ft_flag_r_justified(t_flags *flags, int v_len);
void	ft_flag_l_justified(t_flags *flags, int v_len);
void	ft_put_precision(t_flags flags, long long local_pa, int base, int maj);

/*Flags*/
int		ft_flag_spaces(char *str, int *index);
int		ft_flag_zero(char *str, int *index, t_flags *flags);
int		ft_flag_preci(char *str, int *index);
int		ft_flag_length(char *str, int *index);
int		ft_flag_bool(int *index);

int		ft_conv_percent(t_flags flags);
int		ft_conv_char(t_flags flags, char c);

/*i & d*/
void	ft_put_preci_int_ll(t_flags *flags, long long local_pa);
void	ft_put_preci_int_l(t_flags *flags, long long local_pa);
void	ft_put_preci_int(t_flags *flags, long long local_pa);
int		ft_launch_conv_d_i(va_list *pa, t_flags flags, char *str, int index);
void	ft_before_d_i(t_flags *flags, int v_len, long long local_pa);
void	ft_after_d_i(t_flags *flags, int v_len, long long local_pa);
int		ft_conv_d_i(va_list pa, t_flags flags);
int		ft_conv_d_i_l(va_list pa, t_flags flags);
int		ft_conv_d_i_ll(va_list pa, t_flags flags);
int		ft_conv_d_i_h(va_list pa, t_flags flags);
int		ft_conv_d_i_hh(va_list pa, t_flags flags);
int		ft_conv_d_i_j(va_list pa, t_flags flags);
int		ft_conv_d_i_z(va_list pa, t_flags flags);


/*x & X*/
void	ft_put_preci_hex_ll(t_flags *flags, long long local_pa, int maj);
void	ft_put_preci_hex(t_flags *flags, long long local_pa, int maj);
void	ft_before_x(t_flags *flags, int v_len, long long value, int maj);
void	ft_after_hex(t_flags *flags, int v_len);
int		ft_launch_conv_x_X(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_x(va_list pa, t_flags flags, char *str);
int		ft_conv_x_l(va_list pa, t_flags flags, char *str);
int		ft_conv_x_hh(va_list pa, t_flags flags, char *str);
int		ft_conv_X(va_list pa, t_flags flags, char *str);
int		ft_conv_X_l(va_list pa, t_flags flags, char *str);
int		ft_conv_X_hh(va_list pa, t_flags flags, char *str);

/*u & U*/
void	ft_put_preci_uni_ll(t_flags *flags, long long local_pa);
void	ft_put_precision_uni(t_flags *flags, long long local_pa);
void	ft_before_u(t_flags *flags, int v_len, long long local_pa);
void	ft_after_u(t_flags *flags, int v_len);
int		ft_launch_conv_u_U(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_u(va_list pa, t_flags flags);
int		ft_conv_u_l(va_list pa, t_flags flags);
int		ft_conv_u_hh(va_list pa, t_flags flags);
int		ft_conv_u_z(va_list pa, t_flags flags);
int		ft_conv_u_j(va_list pa, t_flags flags);

/*s & S*/
void	ft_put_precision_str(t_flags flags, char *local_pa, int len);
void	ft_before_str(t_flags *flags, int v_len);
void	ft_after_str(t_flags *flags, int v_len);
int		ft_launch_conv_s_S(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_s(va_list pa, t_flags flags);

/*o & O*/
void	ft_put_precision_oct_ll(t_flags *flags, long long local_pa);
void	ft_put_precision_oct(t_flags *flags, long long local_pa);
void	ft_before_o(t_flags *flags, int v_len, int index, long long local_pa);
void	ft_after_o(t_flags *flags, int v_len);
int		ft_launch_conv_o_O(va_list *pa, t_flags flags, char *str, int index);
int		ft_conv_o(va_list pa, t_flags flags);
int		ft_conv_o_ll(va_list pa, t_flags flags);
int		ft_conv_o_hh(va_list pa, t_flags flags);

int		ft_conv_c(va_list pa, t_flags flags);
int		ft_conv_p(va_list *pa, t_flags flags);


#endif
