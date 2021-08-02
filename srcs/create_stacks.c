/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:16:35 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:24:18 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int create_stacks(t_general *mother, char **av)
{
    int i;
    int j;

    // for (int i = 0; av[i]; i++)
    //     ft_putstr_fd(av[i], 1);

    // mother->stack_a_head = mother->stack_a;
 
    mother->stack_a = (t_stack *)malloc(sizeof(t_stack) * (mother->stack_length + 1));
    mother->stack_b = (t_stack *)malloc(sizeof(t_stack) * (mother->stack_length + 1));
    i = 1;
    j = 0;
    while (i <= mother->stack_length)
    {
        mother->stack_a[j].data = av[i];
        mother->stack_a[j].is_full = 1;
        mother->stack_b[j].is_full = 0;
        j++;
        i++;
    }
    mother->stack_a[j].is_full = 0;
    mother->stack_b[j].is_full = 0;
    ft_printf("_________________________________________\nInit a and b:\n");
    display_stacks(mother);
    return (0);
}