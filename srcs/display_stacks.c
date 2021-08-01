/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:26:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/01 22:18:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void display_stacks(t_general *mother)
{
    t_list *temp;

    temp = mother->stack_a;
    while (temp != NULL)
    {
        // {
        //     ft_printf("%d %d\n", ((t_content *)mother->stack_a->content)->elem, ((t_content *)mother->stack_b->content)->elem);
        //     mother->stack_b = mother->stack_b->next;
        // }
        // else
            ft_printf("%d  \n", (temp->content));
        
        temp = temp->next;

    }
    ft_printf("   \n_ _\na b\n");
}