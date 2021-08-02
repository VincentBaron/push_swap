/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:57:19 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:05:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void rra_operation(t_general *mother)
{
    t_list *head;
    t_content *temp;

    head = mother->stack_a;
    if (head->next != NULL)
    {
        while (head->next != NULL)
        {
            temp = head->next->content;
            head->next->content = head->content;
        }
        mother->stack_a->content = temp;
    }
}

void rrb_operation(t_general *mother)
{
    (void)mother;
}

void rrr_operation(t_general *mother)
{
    (void)mother;
}