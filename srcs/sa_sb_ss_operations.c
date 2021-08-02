/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:19:28 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 15:56:41 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa_operation(t_general *mother)
{
    t_list *temp;
    
    mother->stack_a_head = mother->stack_a;
    if (mother->stack_a->next)
    {
        temp = mother->stack_a_head->content;
        mother->stack_a_head->content = mother->stack_a_head->next->content;
        mother->stack_a_head->next->content = temp;
    }
}

void sb_operation(t_general *mother)
{
   t_content *temp;
    
    mother->stack_b_head = mother->stack_b;
    if (mother->stack_b->next)
    {
        temp = mother->stack_b_head->content;
        mother->stack_b_head->content = mother->stack_b_head->next->content;
        mother->stack_b_head->next->content = temp;
    }
}

void ss_operation(t_general *mother)
{
    sa_operation(mother);
    sb_operation(mother);
}