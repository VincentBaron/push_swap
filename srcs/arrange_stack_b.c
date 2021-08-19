/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:43:27 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/19 15:45:47 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_stack_b(t_general *mother)
{
	calculate_pos(&(mother->stack_b));
	if (mother->stack_b.max < (mother->stack_b.len / 2))
	{
		while (mother->stack_b.max > 0)
		{
			rb_operation(mother);
			mother->stack_b.max--;
		}
	}
	else
	{
		while (mother->stack_b.max < mother->stack_b.len)
		{
			rrb_operation(mother);
			mother->stack_b.max++;
		}
	}
}

void	arrange_stack_b(t_general *mother)
{
	if (mother->stack_b.len == 2
		&& mother->stack_b.data[0] < mother->stack_b.data[1])
		sb_operation(mother);
	find_nearest_lowest(mother);
	if (mother->stack_b.nearest == -1)
	{
		calculate_pos(&(mother->stack_b));
		mother->stack_b.nearest = mother->stack_b.min + 1;
	}
	if (mother->stack_b.nearest < mother->stack_b.len / 2)
	{
		while (mother->stack_b.nearest > 0)
		{
			rb_operation(mother);
			mother->stack_b.nearest--;
		}
	}
	else
	{
		while (mother->stack_b.nearest < mother->stack_b.len)
		{
			rrb_operation(mother);
			mother->stack_b.nearest++;
		}
	}
}
