/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:51:41 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/05 12:11:23 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra_operation(t_general *mother)
{
    int i;
    int first;
    int temp;


    ft_printf("ra\n\n");
    if (mother->stack_a.len < 2)
        return;
    i = 0;
    first = mother->stack_a.data[i];
    while (i + 1 < mother->stack_a.len)
    {
        temp = mother->stack_a.data[i];
        mother->stack_a.data[i] = mother->stack_a.data[i + 1];
        i++;
    }
    mother->stack_a.data[i] = first;
    display_stacks(mother);
    mother->turn++;
}

void rb_operation(t_general *mother)
{
    int i;
    int first;
    int temp;


    ft_printf("ra\n\n");
    if (mother->stack_b.len < 2)
        return;
    i = 0;
    first = mother->stack_b.data[i];
    while (i + 1 < mother->stack_b.len)
    {
        temp = mother->stack_b.data[i];
        mother->stack_b.data[i] = mother->stack_b.data[i + 1];
        i++;
    }
    mother->stack_b.data[i] = first;
    display_stacks(mother);
    mother->turn++;
}

void rr_operation(t_general *mother)
{
    
    ft_printf("rr\n\n");
    ra_operation(mother);
    rb_operation(mother);
    display_stacks(mother);
}
