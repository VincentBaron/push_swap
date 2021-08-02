/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:51:08 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:01:40 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void do_operation(t_general *mother, char *op)
{
    mother->op_string = ft_strjoin(mother->op_string, op);
    ft_printf("%s:\n", mother->op_string);
    if (ft_strncmp(op, "sa", ft_strlen(op)) == 0)
        sa_operation(mother);
    if (ft_strncmp(op, "sb", ft_strlen(op)) == 0)
        sb_operation(mother);
    if (ft_strncmp(op, "ss", ft_strlen(op)) == 0)
        ss_operation(mother);
    if (ft_strncmp(op, "ra", ft_strlen(op)) == 0)
        ra_operation(mother);
    if (ft_strncmp(op, "rb", ft_strlen(op)) == 0)
        rb_operation(mother);
    if (ft_strncmp(op, "rr", ft_strlen(op)) == 0)
        rr_operation(mother);
    if (ft_strncmp(op, "rra", ft_strlen(op)) == 0)
        rra_operation(mother);
    if (ft_strncmp(op, "rrb", ft_strlen(op)) == 0)
        rrb_operation(mother);
    if (ft_strncmp(op, "rrr", ft_strlen(op)) == 0)
        rrr_operation(mother);    
    display_stacks(mother);
}