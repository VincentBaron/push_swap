/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:34:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 16:29:46 by vbaron           ###   ########.fr       */
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
		if (minus > 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_general	mother;

	if (ac < 2)
		return (1);
	if (!check_args(av))
	{
		printf("Error\n");
		return (1);
	}
	init_vars(&mother);
	mother.stack_length = ac - 1;
	create_stacks(&mother, av);
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
