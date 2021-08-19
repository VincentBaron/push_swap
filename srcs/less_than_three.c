/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:20:14 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/19 15:09:57 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	less_than_three(t_general *mother)
{
	calculate_pos(&(mother->stack_a));
	while (!is_sorted(&mother->stack_a))
	{
		if (mother->stack_a.len < 3
			|| (mother->stack_a.max == 2 && mother->stack_a.min == 1))
			sa_operation(mother);
		else if (mother->stack_a.max == 0 && mother->stack_a.min == 1)
			ra_operation(mother);
		else if (mother->stack_a.max == 1 && mother->stack_a.min == 2)
			rra_operation(mother);
		else if (mother->stack_a.max == 0 && mother->stack_a.min == 2)
		{
			sa_operation(mother);
			rra_operation(mother);
		}
		else if (mother->stack_a.max == 1 && mother->stack_a.min == 0)
		{
			sa_operation(mother);
			ra_operation(mother);
		}
	}
}
