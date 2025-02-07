/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:51:55 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 18:30:57 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void find_push_max(t_push_swap *ps)
{
    int max_index;
    int half;

    max_index = find_max_index(ps->stack_b);
    half = ps->stack_b->size / 2;

    if (max_index <= half)
    {
        while (ps->stack_b->data[0] != get_max_value(ps->stack_b))
            rb(ps);
    }
    else
    {
        while (ps->stack_b->data[0] != get_max_value(ps->stack_b))
            rrb(ps);
    }
    pa(ps); 
}

int get_max_value(t_stack *stack)
{
    int max;
    int i;

    max = INT_MIN;
    i = 0;
    while (i < stack->size)
    {
        if (stack->data[i] > max)
            max = stack->data[i];
        i++;
    }
    return (max);
}

int find_max_index(t_stack *stack)
{
    int max;
    int i;

    max = get_max_value(stack);
    i = 0;
    while (i < stack->size)
    {
        if (stack->data[i] == max)
            return (i);
        i++;
    }
    return (-1);
}