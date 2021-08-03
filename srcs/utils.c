/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:22:00 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/03 15:26:32 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i + 1 < stack->len)
    {
        if (stack->data[i + 1] < stack->data[i])
            return (0);
        i++;
    }
    return (1);
}