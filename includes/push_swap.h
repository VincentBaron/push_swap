/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:47:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/17 11:35:17 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
# include "stdlib.h"
#include "../libft/libft.h"


typedef struct s_stack
{
    int *data;
    int max;
    int min;
    int len;
    int hold_first;
    int hold_second;
    int *chunks;
    int nearest;
} t_stack;

typedef struct s_general
{
    int stack_length;
    t_stack stack_a;
    t_stack stack_b;
    int offset;
    char *op_string;
    int turn;
    int *sorted_stack;
    int elem_to_move;
} t_general;

int create_stacks(t_general *mother, char **av);
void sa_operation(t_general *mother);
void sb_operation(t_general *mother);
void ss_operation(t_general *mother);
void display_stacks(t_general *mother);
void ra_operation(t_general *mother);
void rb_operation(t_general *mother);
void rr_operation(t_general *mother);
void rra_operation(t_general *mother);
void rrb_operation(t_general *mother);
void rrr_operation(t_general *mother);
void pa_operation(t_general *mother);
void pb_operation(t_general *mother);
void less_than_three(t_general *mother);
void less_than_five(t_general *mother);
int is_sorted(t_stack *stack);
void calculate_pos(t_stack *stack);
void more_than_five(t_general *mother, int size);
void create_sorted_stack(t_general *mother);
void push_chunk(t_general *mother);
void find_holds(t_general *mother, int chunk_top);
void create_malloc(t_general *mother);
void find_nearest_lowest(t_general *mother);
void create_chunks(t_general *mother, int size);