/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:26:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:49:07 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void display_stacks(t_general *mother)
{
    int i;

    i = 0;
    // ft_printf("stack length: %d\n\n",mother->stack_length);
    while (i < mother->stack_length)
    {
        if (mother->stack_a[i].is_full == 1)
            ft_printf("%d", mother->stack_a[i].data);
        if (mother->stack_b[i].is_full == 1)
            ft_printf("%d", mother->stack_b[i].data);
        ft_printf("\n");
        i++;
    }
    ft_printf("_ _\na b\n");
}