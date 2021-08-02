/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:26:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:34:00 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void display_stacks(t_general *mother)
{
    int i;

    i = 0;
    ft_printf("stack_a = ");
    while (i <= mother->stack_length)
    {
        if (mother->stack_a[i].is_full == 1)
            ft_printf("%d", mother->stack_a[i].data);
        
    }
    ft_printf("stack_b = ");
    while (i <= mother->stack_length)
    {
        if (mother->stack_b[i].is_full == 1)
            ft_printf("%d", mother->stack_b[i].data);
        
    }

    ft_printf("_ _\na b\n");
}