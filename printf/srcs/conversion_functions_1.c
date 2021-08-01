/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:12:07 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/16 18:46:15 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	conv_per(va_list args, t_flags *general)
{
	(void)args;
	if (general->minus == 0)
	{
		ft_printwidth_s(general, "%");
		ft_printchar('%', general);
	}
	else
	{
		ft_printchar('%', general);
		ft_printwidth_s(general, "%");
	}
}

void	conv_c(va_list args, t_flags *general)
{
	char	c;

	c = va_arg(args, int);
	if (general->minus == 0)
	{
		ft_printwidth_s(general, "%");
		ft_printchar(c, general);
	}
	else
	{
		ft_printchar(c, general);
		ft_printwidth_s(general, "%");
	}
}

void	conv_s(va_list args, t_flags *general)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (general->minus == 0)
	{
		ft_printwidth_s(general, s);
		ft_printstr(s, general);
	}
	else
	{
		ft_printstr(s, general);
		ft_printwidth_s(general, s);
	}
}

void	conv_p(va_list args, t_flags *general)
{
	unsigned long int	p;
	char				*s;

	p = va_arg(args, unsigned long int);
	if (general->width == 0 && general->precision == 0)
	{
		print_prefix_p(general);
		return ;
	}
	s = ft_itoa_hex(p);
	if (p == 0 && general->precision > -1)
		s = NULL;
	if (general->minus == 0)
	{
		ft_printwidth_pxbigx(general, s);
		print_prefix_p(general);
		ft_printpxbigx(s, general);
	}
	else
	{
		print_prefix_p(general);
		ft_printpxbigx(s, general);
		ft_printwidth_pxbigx(general, s);
	}
	free(s);
}

void	conv_d(va_list args, t_flags *general)
{
	long int	d;

	d = va_arg(args, int);
	if (general->zero == 1 && general->width > 0 && general->precision == -1)
	{
		general->precision = general->width - (d < 0 ? 1 : 0);
		general->width = 0;
	}
	if (general->minus == 0)
	{
		ft_printwidth_diu(general, d);
		ft_printnbr(d, general);
	}
	else
	{
		ft_printnbr(d, general);
		ft_printwidth_diu(general, d);
	}
}
