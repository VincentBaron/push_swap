/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:51:41 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 15:15:17 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra_operation(t_general *mother)
{
    t_content *temp;
    t_list *head;
    
    head = mother->stack_a;
    temp = mother->stack_a->content;
    if (head->next)
    {
        while (head->next != NULL)
            head = head->next;
        mother->stack_a->content = head->content;
        head->content = temp;
    }
}

void rb_operation(t_general *mother)
{
    t_content *temp;
    t_list *head;
    
    head = mother->stack_b;
    temp = mother->stack_b->content;
    if (mother->stack_b->next)
    {
        while (head->next != NULL)
            head = head->next;
        mother->stack_b->content = head->content;
        head->content = temp;
    }
}

void rr_operation(t_general *mother)
{
    ra_operation(mother);
    rb_operation(mother);
}
