/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:47:26 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/01 10:19:17 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	end_pa(t_general *mother, int *new_a, int *new_b)
{
	if (mother->stack_a.len > 1)
		free(mother->stack_a.data);
	free(mother->stack_b.data);
	mother->stack_a.data = new_a;
	mother->stack_b.data = new_b;
	mother->turn++;
	if (mother->stack_b.len == 0)
		free(new_b);
}

void	check_malloc(int *new_a, int *new_b)
{
	if (!new_b)
		error();
	if (!new_a)
		error();
}

void	pa_operation(t_general *mother)
{
	int	*new_a;
	int	*new_b;
	int	i;

	printf("pa\n");
	if (mother->stack_b.len <= 0)
		return ;
	mother->stack_a.len++;
	mother->stack_b.len--;
	new_b = (int *)malloc(sizeof(int) * (mother->stack_b.len));
	new_a = (int *)malloc(sizeof(int) * (mother->stack_a.len));
	check_malloc(new_a, new_b);
	i = -1;
	while (++i < mother->stack_b.len)
		new_b[i] = mother->stack_b.data[i + 1];
	new_a[0] = mother->stack_b.data[0];
	i = -1;
	while (++i + 1 < mother->stack_a.len)
		new_a[i + 1] = mother->stack_a.data[i];
	end_pa(mother, new_a, new_b);
}

void	end_pb(t_general *mother, int *new_a, int *new_b)
{
	if (mother->stack_b.len > 1)
		free(mother->stack_b.data);
	free(mother->stack_a.data);
	mother->stack_a.data = new_a;
	mother->stack_b.data = new_b;
	mother->turn++;
	if (mother->stack_a.len == 0)
		free(new_a);
}

void	pb_operation(t_general *mother)
{
	int	*new_a;
	int	*new_b;
	int	i;

	printf("pb\n");
	if (mother->stack_a.len <= 0)
		return ;
	mother->stack_b.len++;
	mother->stack_a.len--;
	new_b = (int *)malloc(sizeof(int) * (mother->stack_b.len));
	new_a = (int *)malloc(sizeof(int) * (mother->stack_a.len));
	check_malloc(new_a, new_b);
	i = -1;
	while (++i < mother->stack_a.len)
		new_a[i] = mother->stack_a.data[i + 1];
	new_b[0] = mother->stack_a.data[0];
	i = -1;
	while (++i + 1 < mother->stack_b.len)
		new_b[i + 1] = mother->stack_b.data[i];
	end_pb(mother, new_a, new_b);
}
