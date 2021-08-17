/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:51:41 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 14:44:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra_operation(t_general *mother)
{
    int i;
    int first;

    printf("ra\n");
    if (mother->stack_a.len < 2)
        return;
    i = 0;
    first = mother->stack_a.data[i];
    while (i + 1 < mother->stack_a.len)
    {
        mother->stack_a.data[i] = mother->stack_a.data[i + 1];
        i++;
    }
    mother->stack_a.data[i] = first;
    mother->turn++;
}

void rb_operation(t_general *mother)
{
    int i;
    int first;

    printf("rb\n");
    if (mother->stack_b.len < 2)
        return;
    i = 0;
    first = mother->stack_b.data[i];
    while (i + 1 < mother->stack_b.len)
    {
        mother->stack_b.data[i] = mother->stack_b.data[i + 1];
        i++;
    }
    mother->stack_b.data[i] = first;
    mother->turn++;
}

void rr_operation(t_general *mother)
{
    printf("rr\n");
    ra_operation(mother);
    rb_operation(mother);
}
