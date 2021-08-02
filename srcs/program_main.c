/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:34:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 17:07:29 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_general mother;

    mother.op_string = ft_substr("------------------------------------------------------\nExec ", 0, ft_strlen("\n------------------------------------------------------\n\nExec "));
    mother.stack_length = ac - 1;
    create_stacks(&mother, av);
    do_operation(&mother, "sa");
    do_operation(&mother, "ra");
    do_operation(&mother, "rra");
}