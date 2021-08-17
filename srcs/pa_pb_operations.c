/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:47:26 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 11:05:26 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void update_stacks(t_general *mother, int *new_a, int *new_b)
{
    mother->stack_a.data = new_a;
    mother->stack_b.data = new_b;
    mother->turn++;
}

void pa_operation(t_general *mother)
{
    int *new_a;
    int *new_b;
    int i;

    if (mother->stack_b.len <= 0)
        return;
    ft_printf("pa\n");
    mother->stack_a.len++;
    mother->stack_b.len--;
    new_b = (int *)malloc(sizeof(int) * (mother->stack_b.len));
    new_a = (int *)malloc(sizeof(int) * (mother->stack_a.len));
    i = 0;
    while (i < mother->stack_b.len)
    {
        new_b[i] = mother->stack_b.data[i + 1];
        i++;
    }
    new_a[0] = mother->stack_b.data[0];
    i = 0;
    while (i + 1 < mother->stack_a.len)
    {
        new_a[i + 1] = mother->stack_a.data[i];
        i++;
    }
    update_stacks(mother, new_a, new_b);
}

void pb_operation(t_general *mother)
{
    int *new_a;
    int *new_b;
    int i;

    if (mother->stack_a.len <= 0)
        return;
    ft_printf("pb\n");
    mother->stack_b.len++;
    mother->stack_a.len--;
    new_b = (int *)malloc(sizeof(int) * (mother->stack_b.len));
    new_a = (int *)malloc(sizeof(int) * (mother->stack_a.len));
    i = 0;
    while (i < mother->stack_a.len)
    {
        new_a[i] = mother->stack_a.data[i + 1];
        i++;
    }
    new_b[0] = mother->stack_a.data[0];
    i = 0;
    while (i + 1 < mother->stack_b.len)
    {
        new_b[i + 1] = mother->stack_b.data[i];
        i++;
    }
    update_stacks(mother, new_a, new_b);
}