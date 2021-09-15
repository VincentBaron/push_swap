/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:34:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/15 12:15:26 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_vars(t_general *mother)
{
	mother->stack_b.len = -1;
	mother->stack_b.max = -1;
	mother->stack_b.min = -1;
	mother->stack_b.hold_first = -1;
	mother->stack_b.hold_second = -1;
	mother->stack_a.len = -1;
	mother->stack_a.max = -1;
	mother->stack_a.min = -1;
	mother->stack_a.hold_first = -1;
	mother->stack_a.hold_second = -1;
}

int	check_args(char **av)
{
	int	i;
	int	f;
	int	minus;

	i = 1;
	while (av[i])
	{
		f = 0;
		minus = 0;
		while (av[i][f])
		{
			if ((av[i][f] < '0' || av[i][f] > '9') && av[i][f] != '-')
				return (0);
			if (av[i][f] == '-')
				minus++;
			f++;
		}
		if ((minus == 1 && ft_strlen(av[i]) > 11) || (minus == 0
				&& ft_strlen(av[i]) > 10) || ft_strlen(av[i]) == 0)
			return (0);
		if (minus > 1)
			return (0);
		i++;
	}
	return (1);
}

void	error(void)
{
	printf("Error\n");
	exit (-1);
}

int	main(int ac, char **av)
{
	t_general	mother;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		error();
	init_vars(&mother);
	mother.stack_length = ac - 1;
	create_stacks(&mother, av);
	if (is_sorted(&(mother.stack_a)))
	{
		free(mother.stack_a.data);
		return (0);
	}
	mother.turn = 0;
	if (mother.stack_length <= 3)
		less_than_three(&mother);
	else if (mother.stack_length <= 5)
		less_than_five(&mother);
	else if (mother.stack_length <= 100)
		more_than_five(&mother, 100);
	else if (mother.stack_length > 100)
		more_than_five(&mother, 500);
	free(mother.stack_a.data);
	return (0);
}
