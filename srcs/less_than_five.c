/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:18:27 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/19 15:09:05 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_offset(t_general *mother)
{
	mother->offset = 0;
	while (mother->stack_a.data[mother->offset])
	{
		if (mother->stack_a.data[mother->offset] > mother->stack_b.data[0])
			break ;
		mother->offset++;
	}
}

void	move_min_value(t_general *mother)
{
	if (mother->stack_a.min <= mother->stack_a.len / 2)
	{
		while (mother->stack_a.min > 0)
		{
			ra_operation(mother);
			mother->stack_a.min--;
		}
	}
	else
	{
		while (mother->stack_a.min < mother->stack_a.len)
		{
			rra_operation(mother);
			mother->stack_a.min++;
		}
	}
}

void	less_than_five(t_general *mother)
{
	while (!is_sorted(&mother->stack_a))
	{
		while (mother->stack_a.len > 3)
		{
			calculate_pos(&mother->stack_a);
			move_min_value(mother);
			pb_operation(mother);
		}
		less_than_three(mother);
		pa_operation(mother);
		pa_operation(mother);
	}
}
