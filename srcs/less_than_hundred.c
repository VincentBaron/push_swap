/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:14:58 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/16 19:25:33 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_chunks(t_general *mother, int size)
{
    int i;
    int f;
    int len;

    i = 1;
    f = 0;
    len = 0;
    if (size == 100)
        len = 5;
    else if (size == 500)
        len = 11;
    mother->stack_a.chunks = (int *)malloc(sizeof(int) * len);
    if (!mother->stack_a.chunks)
        return;
    while (i <= len)
    {
        mother->stack_a.chunks[f] = (mother->stack_length * i) / len - 1;
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
    if (mother->stack_a.hold_first == -1)
        return;
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

void find_nearest_lowest(t_general *mother)
{
    int i;

    i = 0;
    mother->stack_b.nearest = -1;
    while( i < mother->stack_b.len)
    {
        if (mother->stack_b.data[i] < mother->stack_a.data[0])
        {
            if (mother->stack_b.nearest == -1)
                mother->stack_b.nearest = i;
            else if (mother->stack_a.data[0] - mother->stack_b.data[mother->stack_b.nearest] >= mother->stack_a.data[0] - mother->stack_b.data[i])
                mother->stack_b.nearest = i;
        }
        i++;
    }
}

void arrange_stack_b(t_general *mother)
{
    find_nearest_lowest(mother);
    if (mother->stack_b.nearest < mother->stack_b.len / 2)
    {
        while (mother->stack_b.nearest > 0)
        {
            rb_operation(mother);
            mother->stack_b.nearest--;
        }
    }
    else
    {
        while (mother->stack_b.nearest < mother->stack_b.len)
        {
            rrb_operation(mother);
            mother->stack_b.nearest++;
        }
    }
    
}

// void arrange_stack_b(t_general *mother)
// {
//     int i;
//     int offset;

//     i = 0;
//     offset = 0;
//     while (i < mother->stack_b.len)
//     {
//         if (mother->stack_a.data[0] > mother->stack_b.data[i])
//         {
//             offset = i;
//             break;
//         }
//         i++;
//     }
//     if (offset < mother->stack_b.len / 2)
//     {
//         while (offset > 0)
//         {
//             rb_operation(mother);
//             offset--;
//         }
//     }
//     else
//     {
//         while (offset < mother->stack_b.len)
//         {
//             rrb_operation(mother);
//             offset++;
//         }
//     }
// }

void push_chunk(t_general *mother, int size)
{
    int i;
    int f;
    int chunk_top;
    int new_chunk_top;

    create_chunks(mother, size);
    chunk_top = -1;
    i = 0;
    while (mother->stack_a.len > 0)
    {
        new_chunk_top = mother->sorted_stack[mother->stack_a.chunks[i]];
        if (new_chunk_top != chunk_top)
        {
            ft_printf("new chunk top = %d\n\n", new_chunk_top);
            order_stack_b(mother);
            ft_printf("finished ordering stack_b\n\n");
        }
        chunk_top = new_chunk_top;
        mother->stack_a.hold_first = -1;
        mother->stack_a.hold_second = -1;
        find_holds(mother, chunk_top);
        if (mother->stack_a.hold_first != -1)
        {
            mother->elem_to_move = mother->stack_a.hold_second;
            if (mother->stack_a.hold_first < (mother->stack_a.len - mother->stack_a.hold_second))
                mother->elem_to_move = mother->stack_a.hold_first;
            if (mother->elem_to_move < mother->stack_a.len / 2)
            {
                f = 0;
                while (f < mother->elem_to_move)
                {
                    ra_operation(mother);
                    f++;
                }
            }
            else
            {
                f = 0;
                while (f < (mother->stack_a.len - mother->elem_to_move))
                {
                    rra_operation(mother);
                    f++;
                }
            }
            arrange_stack_b(mother);
            pb_operation(mother);
            // order_stack_b(mother);
        }
        else
            i++;
    }
    order_stack_b(mother);
    while (mother->stack_b.len > 0)
        pa_operation(mother);
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

void more_than_five(t_general *mother, int size)
{
    create_sorted_stack(mother);
    push_chunk(mother, size);
}