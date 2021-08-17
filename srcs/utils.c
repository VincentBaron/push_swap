/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:22:00 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 16:33:33 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->len)
	{
		if (stack->data[i + 1] < stack->data[i])
			return (0);
		i++;
	}
	return (1);
}

void	create_malloc(t_general *mother)
{
	mother->sorted_stack = (int *)malloc(sizeof(int) * mother->stack_a.len);
	if (!mother->sorted_stack)
		return ;
}

void	create_sorted_stack(t_general *mother)
{
	int	i;
	int	j;
	int	tmp;

	create_malloc(mother);
	i = 0;
	while (i < mother->stack_a.len)
	{
		mother->sorted_stack[i] = mother->stack_a.data[i];
		i++;
	}
	i = 0;
	while (i + 1 < mother->stack_a.len)
	{
		j = i + 1;
		if (mother->sorted_stack[i] > mother->sorted_stack[j])
		{
			tmp = mother->sorted_stack[i];
			mother->sorted_stack[i] = mother->sorted_stack[j];
			mother->sorted_stack[j] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	find_nearest_lowest(t_general *mother)
{
	int	i;

	i = 0;
	mother->stack_b.nearest = -1;
	while (i < mother->stack_b.len)
	{
		if (mother->stack_b.data[i] < mother->stack_a.data[0])
		{
			if (mother->stack_b.nearest == -1)
				mother->stack_b.nearest = i;
			else if (mother->stack_a.data[0]
				- mother->stack_b.data[mother->stack_b.nearest]
				>= mother->stack_a.data[0] - mother->stack_b.data[i])
				mother->stack_b.nearest = i;
		}
		i++;
	}
}

void	create_chunks(t_general *mother, int size)
{
	int	i;
	int	f;
	int	len;

	i = 1;
	f = 0;
	len = 0;
	if (size == 100)
		len = 5;
	else if (size == 500)
		len = 11;
	mother->stack_a.chunks = (int *)malloc(sizeof(int) * len);
	if (!mother->stack_a.chunks)
		return ;
	while (i <= len)
	{
		mother->stack_a.chunks[f] = (mother->stack_length * i) / len - 1;
		i++;
		f++;
	}
}
