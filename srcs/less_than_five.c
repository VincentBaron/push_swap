/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:18:27 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/03 19:14:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void less_than_five(t_general *mother)
{
    int offset;
    int turn;
    
    pb_operation(mother);
    if (mother->stack_a.len == 4)
        pb_operation(mother);
    less_than_three(mother);
    if (mother->stack_a.data[0] > mother->stack_a.data[mother->stack_a.len - 1])
        ra_operation(mother);
    turn = 0;
    while (!is_sorted(&mother->stack_a) || mother->stack_b.len)
    {
        offset = 0;
        while (mother->stack_a.data[offset])
        {
            if (mother->stack_a.data[offset] > mother->stack_b.data[0])
                break;
            offset++;
        }
        if (offset == 0)
            pa_operation(mother);
        else if (offset == mother->stack_a.len)
        {
            pa_operation(mother);
            ra_operation(mother);
        }
        else if (offset == 1)
        {
            pa_operation(mother);
            sa_operation(mother);
        }
        else if (offset == mother->stack_a.len - 1)
        {
            rra_operation(mother);
            pa_operation(mother);
        }
        else if (offset == mother->stack_a.len - 2)
        {
            rra_operation(mother);
            rra_operation(mother);
            pa_operation(mother);

        }
        if (!mother->stack_b.len)
            rra_operation(mother);
        turn++;
        if (turn > 12)
            break;
    }
    ft_printf("\nturns: %d", turn);
}