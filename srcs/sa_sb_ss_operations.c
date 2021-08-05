/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:19:28 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/05 12:11:38 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa_operation(t_general *mother)
{
    int temp;

    ft_printf("sa\n\n");
    if (mother->stack_a.len < 2)
        return;
    temp = mother->stack_a.data[0];
    mother->stack_a.data[0] = mother->stack_a.data[1];
    mother->stack_a.data[1] = temp;
    display_stacks(mother);
    mother->turn++;
}

void sb_operation(t_general *mother)
{
    int temp;

    ft_printf("sa\n\n");
    if (mother->stack_b.len < 2)
        return;
    temp = mother->stack_b.data[0];
    mother->stack_b.data[0] = mother->stack_b.data[1];
    mother->stack_b.data[1] = temp;
    display_stacks(mother);
    mother->turn++;
}

void ss_operation(t_general *mother)
{
    ft_printf("ss\n\n");
    sa_operation(mother);
    sb_operation(mother);
    display_stacks(mother);
}