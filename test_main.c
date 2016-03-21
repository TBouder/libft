/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 19:43:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include <locale.h>

// Code tenant sur 7 bits : un octet, 0xxxxxxx
// Code tenant sur 11 bits : deux octets, 110xxxxx 10xxxxxx
// Code tenant sur 16 bits : trois octets, 1110xxxx 10xxxxxx 10xxxxxx
// Code tenant sur 21 bits : quatre octets, 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

int		ft_nbrlen_base(long long n, int base) //add_libft
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int		ft_binary_to_decimal(int b) //Add_libft
{
	char	*binary;
	int		len;
	int		i;
	int		r_value;

	len = 0;
	i = -1;
	r_value = 0;
	if (ft_nbrlen_base(b, 10) <= 8)
		len = 8;
	else if (ft_nbrlen_base(b, 10) > 8 && ft_nbrlen_base(b, 10) <= 11)
		len = 11;
	else if (ft_nbrlen_base(b, 10) > 12 && ft_nbrlen_base(b, 10) <= 16)
		len = 12;
	else if (ft_nbrlen_base(b, 10) > 17 && ft_nbrlen_base(b, 10) <= 21)
		len = 17;
	if (!(binary = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_memmove(binary, ft_itoa(b), len);
	while (i++ < len)
		if (binary[i] == '1')
			r_value += ft_power(2, len - i - 1);
	return (r_value);
}

int		*ft_parse_binary(long long b)
{
	int		*nbr;

	if (!(nbr = (int *)malloc(sizeof(int) * ft_nbrlen_base(b, 10))))
		return (NULL);
	if (ft_nbrlen_base(b, 10) < 8)
		nbr[0] = b;
	else if (ft_nbrlen_base(b, 10) >= 8 && ft_nbrlen_base(b, 10) < 11)
	{
		nbr[1] = 10000000 + (b % 1000000);
		nbr[0] = 11000000 + (b / 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 12 && ft_nbrlen_base(b, 10) < 16)
	{
		nbr[2] = 10000000 + (b % 1000000);
		nbr[1] = 10000000 + (b / 1000000 % 1000000);
		nbr[0] = 11100000 + (b / 1000000 / 1000000 % 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 17 && ft_nbrlen_base(b, 10) < 21)
	{
		nbr[3] = 10000000 + (b % 1000000);
		nbr[2] = 10000000 + (b / 1000000 % 1000000);
		nbr[1] = 10000000 + (b / 1000000 / 1000000 % 1000000);
		nbr[0] = 11110000 + (b / 1000000 / 1000000 / 1000000 % 1000000);
	}
	return (nbr);
}


int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	char		*bin;
	int			*nbr;
	int			i;

	i = 0;
	bin = ft_itoa_base(L'米', 2);
	nbr = ft_parse_binary(ft_atoi_ll(bin));
	while (nbr[i])
	{
		nbr[i] = ft_binary_to_decimal(nbr[i]);
		ft_putchar(nbr[i]);
		i++;
	}
	ft_putchar('\n');


	// ft_putnbr(ft_nbrlen_base(L'α', 2));
	// ft_putchar('\n');
	// ft_putnbr_base(11001110, 10, 0);
	// ft_putchar('\n');
	// ft_putnbr_base(10110001, 10, 0);

	return 0;
}

// 1110110001
// 110xxxxx 10xxxxxx
// 11001110 10110001

// 111110001110011
// 1110xxxx 10xxxxxx 10xxxxxx
// 1110.0111 10.110001 10.110011
