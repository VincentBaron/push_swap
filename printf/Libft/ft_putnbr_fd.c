/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:40 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/15 14:12:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			num;
	unsigned int	nx;

	if (n < 0)
		nx = -1 * n;
	else
		nx = n;
	if (nx >= 10)
		ft_putnbr_fd(nx / 10, fd);
	num = nx % 10 + 48;
	ft_putchar_fd(num, fd);
}
