/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:31:58 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 15:35:22 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_pos(t_stack *stack)
{
	int	i;

	i = 0;
	stack->max = i;
	stack->min = i;
	while (i + 1 < stack->len)
	{
		if (stack->data[i + 1] > stack->data[stack->max])
			stack->max = i + 1;
		if (stack->data[i + 1] < stack->data[stack->min])
			stack->min = i + 1;
		i++;
	}
}
