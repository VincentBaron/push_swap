/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:47:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/02 16:23:19 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
# include "stdlib.h"
#include "../libft/libft.h"

#include "../printf/includes/printf.h"


typedef struct s_stack
{
    int data;
    int is_full;
} t_stack;

typedef struct s_general
{
    int stack_length;
    t_stack *stack_a;
    t_stack *stack_b;
    char *op_string;
} t_general;

int create_stacks(t_general *mother, char **av);
void sa_operation(t_general *mother);
void sb_operation(t_general *mother);
void ss_operation(t_general *mother);
void display_stacks(t_general *mother);
void do_operation(t_general *mother, char *op);
void ra_operation(t_general *mother);
void rb_operation(t_general *mother);
void rr_operation(t_general *mother);
void rra_operation(t_general *mother);
void rrb_operation(t_general *mother);
void rrr_operation(t_general *mother);

