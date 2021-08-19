/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:19:28 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/19 13:00:37 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa_operation(t_general *mother)
{
    int temp;

    printf("sa\n");
    if (mother->stack_a.len < 2)
        return;
    temp = mother->stack_a.data[0];
    mother->stack_a.data[0] = mother->stack_a.data[1];
    mother->stack_a.data[1] = temp;
    mother->turn++;
}

void sb_operation(t_general *mother)
{
    int temp;

    printf("sb\n");
    if (mother->stack_b.len < 2)
        return;
    temp = mother->stack_b.data[0];
    mother->stack_b.data[0] = mother->stack_b.data[1];
    mother->stack_b.data[1] = temp;
    mother->turn++;
}

void ss_operation(t_general *mother)
{
    printf("ss\n");
    sa_operation(mother);
    sb_operation(mother);
}