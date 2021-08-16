/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:14:58 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/16 11:40:15 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_chunks(t_general *mother)
{
    int i;
    int f;

    i = 1;
    f = 0;
    while (i <= 5)
    {
        mother->stack_a.chunks_five[f] = (mother->stack_length * i) / 5 - 1;
        printf("chunks_5[%d]= %d", f, mother->stack_a.chunks_five[f]);
        i++;
        f++;
    }
}

void find_holds(t_general *mother, int chunk_top)
{
    int i;

    i = 0;
    while (i < mother->stack_a.len)
    {
        if (mother->stack_a.data[i] <= chunk_top)
        {
            mother->stack_a.hold_first = i;
            break;
        }
        i++;
    }
    i = mother->stack_a.len - 1;
    while (i >= 0)
    {
        if (mother->stack_a.data[i] <= chunk_top)
        {
            mother->stack_a.hold_second = i;
            break;
        }
        i--;
    }
}

void order_stack_b(t_general *mother)
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

void arrange_stack_b(t_general *mother)
{
    int i;
    int offset;

    i = 0;
    while (i < mother->stack_b.len)
    {
        if (mother->stack_a.data[0] > mother->stack_b.data[i])
            offset = i;
        i++;
    }
    if (offset < mother->stack_b.len / 2)
    {
        while (offset > 0)
        {
            rb_operation(mother);
            offset--;
        }
    }
    else
    {
        while (offset < mother->stack_b.len)
        {
            rrb_operation(mother);
            offset++;
        }
    }
}

void push_chunk(t_general *mother)
{
    int i;
    int f;
    int chunk_top;
    int new_chunk_top;

    create_chunks(mother);
    chunk_top = -1;
    i = 0;
    while (mother->stack_a.len > 0)
    {
        new_chunk_top = mother->sorted_stack[mother->stack_a.chunks_five[i]];
        if (new_chunk_top != chunk_top)
            order_stack_b(mother);
        chunk_top = new_chunk_top;
        mother->stack_a.hold_first = -1;
        //printf("chunk max: %d\n\n", (mother->stack_length * mother->stack_a.chunk) / 5 - 1);
        find_holds(mother, chunk_top);
        if (mother->stack_a.hold_first != -1)
        {
            mother->elem_to_move = mother->stack_a.hold_second;
            if (mother->stack_a.hold_first <= (mother->stack_a.len - mother->stack_a.hold_second))
                mother->elem_to_move = mother->stack_a.hold_first;
            f = 0;
            while (f < mother->elem_to_move)
            {
                if (mother->elem_to_move == mother->stack_a.hold_first)
                    ra_operation(mother);
                else
                    rra_operation(mother);
                f++;
            }
            arrange_stack_b(mother);
            pb_operation(mother);
        }
        else
            i++;
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