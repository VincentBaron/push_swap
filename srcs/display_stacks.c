/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:26:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 15:41:03 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stacks(t_general *mother)
{
	int	i;

	i = 0;
	while (i < mother->stack_length)
	{
		if (i < mother->stack_a.len)
			printf("%d", mother->stack_a.data[i]);
		else
			printf(" ");
		printf(" ");
		if (i < mother->stack_b.len)
			printf("%d", mother->stack_b.data[i]);
		else
			printf(" ");
		printf("\n");
		i++;
	}
	printf("_ _\na b\n\n");
}
