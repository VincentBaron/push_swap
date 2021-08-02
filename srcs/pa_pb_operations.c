/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:47:26 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 18:00:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void pa_operation(t_general *mother)
{
    t_stack *new_a;
    t_stack *new_b;
    int new_len;
    int i;

    if (mother->stack_b_len <= 0)
        return;

    new_len = mother->stack_a_len + 2;
    new_a = (t_stack *)malloc(sizeof(t_stack) * (new_len));
    new_b = (t_stack *)malloc(sizeof(t_stack) * (mother->stack_b_len));

    new_a[0] = mother->stack_b[0];
    i = 0;
    while (i < mother->stack_a_len)
    {
        new_a[i + 1] = mother->stack_a[i];
        i++;
    }
    new_a[i] = NULL;
    free(mother->stack_a);
    mother->stack_a = new_a;

}

void pb_operation(t_general *mother)
{

}