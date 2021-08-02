/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:51:41 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 17:07:58 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra_operation(t_general *mother)
{
    t_stack temp;

    if (mother->stack_a_len < 2)
        return;
    temp = mother->stack_a[0];
    mother->stack_a[0] = mother->stack_a[mother->stack_a_len - 1];
    mother->stack_a[mother->stack_a_len - 1] = temp;
}

void rb_operation(t_general *mother)
{
    t_stack temp;

    if (mother->stack_b_len < 2)
        return;
    temp = mother->stack_b[0];
    mother->stack_b[0] = mother->stack_b[mother->stack_b_len - 1];
    mother->stack_b[mother->stack_b_len - 1] = temp;
}

void rr_operation(t_general *mother)
{
    ra_operation(mother);
    rb_operation(mother);
}
