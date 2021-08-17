/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:34:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 11:35:34 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void init_vars(t_general *mother)
{
    mother->stack_b.len = -1;
    mother->stack_b.max = -1;
    mother->stack_b.min = -1;
    mother->stack_b.hold_first = -1;
    mother->stack_b.hold_second = -1;
    mother->stack_a.len = -1;
    mother->stack_a.max = -1;
    mother->stack_a.min = -1;
    mother->stack_a.hold_first = -1;
    mother->stack_a.hold_second = -1;
}

int main(int ac, char **av)
{
    t_general mother;

    init_vars(&mother);
    mother.stack_length = ac - 1;
    create_stacks(&mother, av);
    mother.turn = 0;
    if (mother.stack_length <= 3)
        less_than_three(&mother);
    else if (mother.stack_length <= 5)
        less_than_five(&mother);
    else if (mother.stack_length <= 100)
        more_than_five(&mother, 100);
    else if (mother.stack_length <= 500)
        more_than_five(&mother, 500);
    printf("no of turns: %d", mother.turn);
    if (is_sorted(&(mother.stack_a)))
        printf("\n\n\nSUCCESS!!!!!\n");
}