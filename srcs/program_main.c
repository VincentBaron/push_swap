/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:34:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/16 11:33:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_general mother;

    mother.op_string = ft_substr("------------------------------------------------------\nExec ", 0, ft_strlen("\n------------------------------------------------------\n\nExec "));
    mother.stack_length = ac - 1;
    create_stacks(&mother, av);
    mother.turn = 0;
    if (mother.stack_length <= 3)
        less_than_three(&mother);
    else if (mother.stack_length <= 5)
        less_than_five(&mother);
    else if (mother.stack_length <= 100)
        less_than_hundred(&mother);
    printf("no of turns: %d", mother.turn);
}