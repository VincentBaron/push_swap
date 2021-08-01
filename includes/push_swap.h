/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:47:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/01 22:14:44 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
# include "stdlib.h"
#include "../libft/libft.h"

#include "../printf/includes/printf.h"


typedef struct s_content
{
    int elem;
} t_content;

typedef struct s_general
{
    int stack_length;
    t_list *stack_a;
    t_list *stack_a_head;
    t_list *stack_b;
    t_list *stack_b_head;
} t_general;

int create_stacks(t_general *mother, char **av);
void sa_operation(t_general *mother);
void sb_operation(t_general *mother);
void ss_operation(t_general *mother);
void display_stacks(t_general *mother);
void do_operation(t_general *mother, char *op);
