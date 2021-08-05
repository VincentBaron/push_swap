/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:18:27 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/05 12:40:38 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void calculate_offset(t_general *mother)
{
    mother->offset = 0;
        while (mother->stack_a.data[mother->offset])
        {
            if (mother->stack_a.data[mother->offset] > mother->stack_b.data[0])
                break;
            mother->offset++;
        }
}

void less_than_five(t_general *mother)
{
    int turn;
    

    if (is_sorted(&mother->stack_a))
        return;
    pb_operation(mother);
    if (mother->stack_a.len == 4)
        pb_operation(mother);
    less_than_three(mother);
    turn = 0;
    while (!is_sorted(&mother->stack_a) || mother->stack_b.len)
    {
        calculate_offset(mother);
        if (mother->offset == 0)
            pa_operation(mother);
        else if (mother->offset == mother->stack_a.len)
        {
            pa_operation(mother);
            ra_operation(mother);
        }
        else if (mother->offset == 1)
        {
            pa_operation(mother);
            sa_operation(mother);
        }
        else if (mother->offset == mother->stack_a.len - 1)
        {
            rra_operation(mother);
            pa_operation(mother);
        }
        else if (mother->stack_b.len == 1 && mother->offset == 2)
        {
            ra_operation(mother);
            ra_operation(mother);
            pa_operation(mother);
        }
        if (mother->stack_b.len == 0 && !is_sorted(&mother->stack_a))
        {
            calculate_pos(&mother->stack_a);
            if (mother->stack_a.max < (mother->stack_a.len < 2))
                ra_operation(mother);
            else
                rra_operation(mother);
            
        }
        turn++;
        if (turn > 12)
            break;
    }
    ft_printf("\nturns: %d", mother->turn);
}