/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:16:35 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 11:04:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int create_stacks(t_general *mother, char **av)
{
    int i;
    int j;
    
    mother->stack_a.len = mother->stack_length;
    mother->stack_a.data = (int *)malloc(sizeof(int) * (mother->stack_a.len + 1));
    mother->stack_b.len = 0;
    i = 1;
    j = 0;
    while (i <= mother->stack_length)
    {
        mother->stack_a.data[j] = ft_atoi(av[i]);
        j++;
        i++;
    }
    return (0);
}