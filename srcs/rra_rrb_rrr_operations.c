/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:57:19 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 17:46:36 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void rra_operation(t_general *mother)
{
    int i;
    t_stack last;
    t_stack temp;
    
    if (mother->stack_a_len < 2)
        return;
    i = mother->stack_a_len - 1;
    last = mother->stack_a[mother->stack_a_len - 1];
    while (i > 0)
    {
        temp = mother->stack_a[i];
        mother->stack_a[i] = mother->stack_a[i - 1];
        i--;
    }
    mother->stack_a[i] = last;
}

void rrb_operation(t_general *mother)
{
    int i;
    t_stack last;
    t_stack temp;
    
    if (mother->stack_b_len < 2)
        return;
    i = mother->stack_b_len - 1;
    last = mother->stack_b[mother->stack_b_len - 1];
    while (i > 0)
    {
        temp = mother->stack_b[i];
        mother->stack_b[i] = mother->stack_b[i - 1];
        i--;
    }
    mother->stack_b[i] = last;
}

void rrr_operation(t_general *mother)
{
    rra_operation(mother);
    rrb_operation(mother);
}