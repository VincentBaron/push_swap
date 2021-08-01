/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 10:57:46 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/16 13:17:41 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		x_calculator(t_flags *general, int n)
{
	int	x;

	x = 0;
	if (n < 0)
	{
		x++;
		n *= -1;
	}
	if (general->precision == 0)
		return (0);
	x += (general->precision > nb_size(n) ? general->precision : nb_size(n));
	return (x);
}

int		z_calculator(t_flags *general, char *str)
{
	int	z;

	z = 0;
	if (general->precision == 0)
		return (0);
	if (general->converter == 3)
		z += 2;
	z += (general->precision > (int)ft_strlen(str) ?
			general->precision : (int)ft_strlen(str));
	return (z);
}

void	print_prefix_p(t_flags *general)
{
	ft_putstr_fd("0x", 1);
	general->bytes += 2;
}

void	initialise_struct(t_flags *general)
{
	general->converter = -1;
	general->zero = 0;
	general->minus = 0;
	general->precision = -1;
	general->width = 0;
	general->wildcard = 0;
	general->index = "%cspdiuxX";
}
