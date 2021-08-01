/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 00:41:09 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/16 12:23:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		nb_size(long int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void	ft_printwidth_diu(t_flags *general, int n)
{
	int	x;

	if (general->width < 0)
		general->width *= -1;
	x = x_calculator(general, n);
	while (general->width - x > 0)
	{
		if (general->zero == 1)
			ft_printchar('0', general);
		else
			ft_printchar(' ', general);
		general->width--;
	}
}

void	ft_printwidth_pxbigx(t_flags *general, char *str)
{
	int	z;

	if (general->width < 0)
		general->width *= -1;
	z = z_calculator(general, str);
	if (str == NULL)
		z = 2;
	while (general->width - z > 0)
	{
		if (general->zero == 1)
			ft_printchar('0', general);
		else
			ft_printchar(' ', general);
		general->width--;
	}
}

void	ft_printpxbigx(char *str, t_flags *general)
{
	int	x;

	x = general->precision;
	if (x == 0)
		return ;
	while (x - (int)ft_strlen(str) > 0)
	{
		ft_printchar('0', general);
		x--;
	}
	ft_putstr_fd(str, 1);
	general->bytes += ft_strlen(str);
}

char	*ft_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
