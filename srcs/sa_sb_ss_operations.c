/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:19:28 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:57:59 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa_operation(t_general *mother)
{
    t_stack temp;

    if (mother->stack_a_len < 2)
        return;
    temp = mother->stack_a[0];
    mother->stack_a[0] = mother->stack_a[1];
    mother->stack_a[1] = temp;
}

void sb_operation(t_general *mother)
{
       t_stack temp;

    if (mother->stack_b_len < 2)
        return;
    temp = mother->stack_b[0];
    mother->stack_b[0] = mother->stack_b[1];
    mother->stack_b[1] = temp;
}

void ss_operation(t_general *mother)
{
    sa_operation(mother);
    sb_operation(mother);
}