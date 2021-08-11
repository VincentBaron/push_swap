/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:14:58 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/11 10:44:20 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void find_holds(t_general *mother)
{
    int i;

    i = 0;
    while (i < mother->stack_a.len)
    {
        if (mother->stack_a.data[i] < (mother->sorted_stack[mother->stack_length / 5 * mother->stack_a.chunk]))
        {
            mother->stack_a.hold_first = i;
            break;
        }
        i++;
    }
    i = mother->stack_a.len - 1;
    while (i >= 0)
    {
        if (mother->stack_a.data[i] < (mother->sorted_stack[mother->stack_length / 5]))
        {
            mother->stack_a.hold_second = i;
            break;
        }
        i++;
    }
}

void push_chunk(t_general *mother)
{
    int i;
    int f;

    mother->stack_a.hold_first = -1;
    mother->stack_a.chunk = 1;

    i = 0;
    while (mother->stack_a.len > 0)
    {
        if (i > (mother->stack_length / 5 * mother->stack_a.chunk))
            mother->stack_a.chunk++;
        find_holds(mother);
        if (mother->stack_a.hold_first != -1)
        {
            mother->elem_to_move = mother->stack_a.hold_second;
            if (mother->stack_a.hold_first <= (mother->stack_a.len - mother->stack_a.hold_second))
                mother->elem_to_move = mother->stack_a.hold_first;
            // arrange_stack_b(mother);
            f = 0;
            while (f < mother->elem_to_move)
            {
                if (mother->elem_to_move == mother->stack_a.hold_first)
                    ra_operation(mother);
                else
                    rra_operation(mother);
                f++;
            }
            pb_operation(mother);
            i++;
        }
    }
}

void create_sorted_stack(t_general *mother)
{
    int i;
    int j;
    int tmp;

    mother->sorted_stack = (int *)malloc(sizeof(int) * mother->stack_a.len);
    if (!mother->sorted_stack)
        return;
    i = 0;
    while (i < mother->stack_a.len)
    {
        mother->sorted_stack[i] = mother->stack_a.data[i];
        i++;
    }
    i = 0;
    while (i + 1 < mother->stack_a.len)
    {
        j = i + 1;
        if (mother->sorted_stack[i] > mother->sorted_stack[j])
        {
            tmp = mother->sorted_stack[i];
            mother->sorted_stack[i] = mother->sorted_stack[j];
            mother->sorted_stack[j] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

void less_than_hundred(t_general *mother)
{
    int i;
    create_sorted_stack(mother);
    i = 0;
    while (i < mother->stack_length)
    {
        printf("%d\n", mother->sorted_stack[i]);
        i++;
    }
    push_chunk(mother);
}