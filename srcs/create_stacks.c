/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:16:35 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/25 09:05:39 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_doubles(t_general *mother)
{
	int	i;
	int	f;

	i = 0;
	while (i < mother->stack_a.len)
	{
		f = i;
		while (f < mother->stack_a.len)
		{
			if (f != i && mother->stack_a.data[f] == mother->stack_a.data[i])
			{
				free(mother->stack_a.data);
				error();
			}
			f++;
		}
		i++;
	}
}

int	create_stacks(t_general *mother, char **av)
{
	int	i;
	int	j;

	mother->stack_a.len = mother->stack_length;
	mother->stack_a.data = (int *)malloc(sizeof(int)
			* (mother->stack_a.len));
	if (!mother->stack_a.data)
		error();
	mother->stack_b.len = 0;
	i = 1;
	j = 0;
	while (i <= mother->stack_length)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
		{
			free(mother->stack_a.data);
			error();
		}
		mother->stack_a.data[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	check_doubles(mother);
	return (1);
}
