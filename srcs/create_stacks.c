/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:16:35 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/01 22:17:23 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int create_stacks(t_general *mother, char **av)
{
    int i;
    int new_content;
    t_list *new;

    // for (int i = 0; av[i]; i++)
    //     ft_putstr_fd(av[i], 1);

    // mother->stack_a_head = mother->stack_a;
    i = 1;
    while (i <= mother->stack_length)
    {
        new_content = ft_atoi(av[i]);
        new = ft_lstnew(&new_content);
        printf("PUSHING %d\n", new_content);
        ft_lstadd_back(&(mother->stack_a), new);

        // printf("PUSHING %d\n", new_content->elem);
        i++;
    }
    ft_printf("_________________________________________\n Init a and b:\n");
    display_stacks(mother);
    return (0);
}