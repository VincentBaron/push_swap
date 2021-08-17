/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:57:19 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 16:31:20 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_operation(t_general *mother)
{
	int	i;
	int	last;

	printf("rra\n");
	if (mother->stack_a.len < 2)
		return ;
	i = mother->stack_a.len - 1;
	last = mother->stack_a.data[mother->stack_a.len - 1];
	while (i > 0)
	{
		mother->stack_a.data[i] = mother->stack_a.data[i - 1];
		i--;
	}
	mother->stack_a.data[i] = last;
	mother->turn++;
}

void	rrb_operation(t_general *mother)
{
	int	i;
	int	last;

	printf("rrb\n");
	if (mother->stack_b.len < 2)
		return ;
	i = mother->stack_b.len - 1;
	last = mother->stack_b.data[mother->stack_b.len - 1];
	while (i > 0)
	{
		mother->stack_b.data[i] = mother->stack_b.data[i - 1];
		i--;
	}
	mother->stack_b.data[i] = last;
	mother->turn++;
}

void	rrr_operation(t_general *mother)
{
	printf("rrr\n");
	rra_operation(mother);
	rrb_operation(mother);
}
