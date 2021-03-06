/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:14:58 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/19 15:43:45 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_holds(t_general *mother, int chunk_top)
{
	int	i;

	i = 0;
	while (i < mother->stack_a.len)
	{
		if (mother->stack_a.data[i] <= chunk_top)
		{
			mother->stack_a.hold_first = i;
			break ;
		}
		i++;
	}
	if (mother->stack_a.hold_first == -1)
		return ;
	i = mother->stack_a.len - 1;
	while (i >= 0)
	{
		if (mother->stack_a.data[i] <= chunk_top)
		{
			mother->stack_a.hold_second = i;
			break ;
		}
		i--;
	}
}

void	push_chunk(t_general *mother)
{
	int	f;

	mother->elem_to_move = mother->stack_a.hold_second;
	if (mother->stack_a.hold_first
		< (mother->stack_a.len - mother->stack_a.hold_second))
		mother->elem_to_move = mother->stack_a.hold_first;
	f = 0;
	if (mother->elem_to_move < mother->stack_a.len / 2)
	{
		while (f < mother->elem_to_move)
		{
			ra_operation(mother);
			f++;
		}
	}
	else
	{
		while (f < (mother->stack_a.len - mother->elem_to_move))
		{
			rra_operation(mother);
			f++;
		}
	}
	arrange_stack_b(mother);
	pb_operation(mother);
}

void	end_more_than_five(t_general *mother)
{
	while (mother->stack_b.len > 0)
		pa_operation(mother);
	free(mother->stack_a.chunks);
	free(mother->sorted_stack);
}

void	more_than_five(t_general *mother, int size)
{
	int	i;
	int	chunk_top;
	int	new_chunk_top;

	create_sorted_stack(mother);
	create_chunks(mother, size);
	chunk_top = -1;
	i = 0;
	while (mother->stack_a.len > 0)
	{
		new_chunk_top = mother->sorted_stack[mother->stack_a.chunks[i]];
		if (new_chunk_top != chunk_top)
			order_stack_b(mother);
		chunk_top = new_chunk_top;
		mother->stack_a.hold_first = -1;
		mother->stack_a.hold_second = -1;
		find_holds(mother, chunk_top);
		if (mother->stack_a.hold_first != -1)
			push_chunk(mother);
		else
			i++;
	}
	order_stack_b(mother);
	end_more_than_five(mother);
}
