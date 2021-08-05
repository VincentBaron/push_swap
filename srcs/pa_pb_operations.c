/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:47:26 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/05 11:52:46 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void pa_operation(t_general *mother)
{
    int *new_a;
    int *new_b;
    int i;


    ft_printf("pb\n\n");
    if (mother->stack_b.len <= 0)
        return;

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


    free(mother->stack_a.data);
    free(mother->stack_b.data);
    mother->stack_a.data = new_a;
    mother->stack_b.data = new_b;
    display_stacks(mother);
    mother->turn++;
}

void pb_operation(t_general *mother)
{
    int *new_a;
    int *new_b;
    int i;


    ft_printf("pb\n\n");
    if (mother->stack_a.len <= 0)
        return;

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


    free(mother->stack_a.data);
    free(mother->stack_b.data);
    mother->stack_a.data = new_a;
    mother->stack_b.data = new_b;
    display_stacks(mother);
    mother->turn++;
}